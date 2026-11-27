
/-
THIS FILE IMPLEMENTS THE CUSTOM LEAN COMPILER PASS.

WHAT IS THE PURPOSE?
When Lean compiles Main.lean, find the call to `matmul2x2`, read its tensor
input/output types, and write StableHLO text directly to artifacts/matmul.mlir.

IMPORTANT DISTINCTIONS:
- This file runs as part of the COMPILATION PROCESS, not as the tensor program.
- The real matrix multiplication is in Main.lean.
- This is a narrow POC: we build a `stablehlo.dot` template for a marked call.
  We are NOT yet translating arbitrary Lean expressions into MLIR.

READING GUIDE:
1. Read Main.lean first.
2. Here, skim the numbered section headings before reading the code.
3. Sections 3-5 contain technical details of Lean's internal expression
   representation. It's enough to understand their input/output at first.
-/

-- These imports provide the Lean compiler's APIs and TensorLib's tensor types.
import Lean
import TensorLib.Ufunc


-- ================================================================
-- SECTION 1: Give a tensor an explicit shape/type in Lean.
-- ================================================================
--
-- PURPOSE:
-- TensorLib's Tensor type alone doesn't directly expose the specific shape
-- and element type in the function signature the way this POC wants.
-- We wrap it so we can write `TypedTensor [2, 2] Dtype.float32`.
-- The wrapper is for our compiler experiment; `raw` holds the real TensorLib
-- tensor. This does not change how TensorLib multiplies the matrices.

namespace LtomPoc

structure TypedTensor (dimensions : List Nat) (elementType : TensorLib.Dtype) where
  raw : TensorLib.Tensor

end LtomPoc


-- ================================================================
-- SECTION 2: Define the marker used to choose the function to inspect.
-- ================================================================
--
-- PURPOSE:
-- We don't want to translate every function the compiler encounters.
-- This registers our own `@[ltom_poc]` tag, which Main.lean puts on matmul2x2.
-- Later, the pass checks for that tag before generating anything.
--
-- LEAN-SPECIFIC: `initialize` registers the attribute when this module loads.

initialize ltomPocAttr : Lean.TagAttribute ←
  Lean.registerTagAttribute `ltom_poc "Find this function during early LCNF compilation"


-- ================================================================
-- SECTION 3: Read tensor dimensions from Lean's compiler data.
-- ================================================================
--
-- PURPOSE:
-- We want MLIR to say `tensor<2x2xf32>`, rather than hard-coding 2x2
-- without looking at the Lean function's declared type.
--
-- The tricky bit: the compiler does not see `[2, 2]` as source-code text.
-- It sees an internal tree of Lean expressions, called `Expr`.
-- These two helpers read a number, then a list of numbers, from that tree.

-- INPUT: Lean's internal expression representing one natural number.
-- OUTPUT: `some number` if recognized, otherwise `none`.
-- `Option` is Lean's way to say "a value may be missing".

-- FIRST, UNDERSTAND WHAT WE ARE LOOKING AT:
-- `expression` is NOT the number itself. It is a Lean object describing code.
-- For example, Lean might store the source-code number `2` like this:
--
--   Lean.Expr.lit (Lean.Literal.natVal 2)
--
-- Think of two objects nested inside each other:
--   LiteralExpression(NaturalNumberLiteral(2))
--
-- WHAT DOES `match` MEAN?
-- Like a C# switch, it chooses a branch based on what kind of object it got.
-- Unlike an ordinary switch on an enum, it can also extract fields.
--
--   | Lean.Expr.lit (Lean.Literal.natVal number) =>
--
-- means: "If this is a literal expression containing a natural-number
-- literal, extract its number and give that extracted value the name `number`."
-- `number` is a NEW local variable, not an existing variable to compare with.
-- `_` is the default case: match anything else, without giving it a name.
--
-- `Option Nat` is the result type: either `Option.some 2`, for example,
-- or `Option.none` if this code does not recognize the expression.

private def readNaturalNumber (expression : Lean.Expr) : Option Nat :=
  match expression with
  | Lean.Expr.lit (Lean.Literal.natVal number) =>
    -- The simple case: we found the number. Return it as a successful result.
    Option.some number
  | _ =>
    -- If the simple case did not match, try an alternate form.
    -- Lean sometimes represents the number via `OfNat.ofNat` instead
    -- of a direct numeric literal. Handle that common case too.
    -- An "application" means a function being applied to arguments.
    -- `isAppOf` asks: "Is this code calling the named function?"
    -- The double backtick notation names a Lean declaration; it does NOT
    -- call that declaration. This is Lean-specific compiler API syntax.
    if expression.isAppOf ``OfNat.ofNat then
      -- `getAppArgs` retrieves the application's arguments as an array.
      -- `.toList` changes that array into a list for matching.
      match expression.getAppArgs.toList with
      -- This case requires EXACTLY three arguments.
      -- The first and third are ignored (`_`). The middle argument must
      -- be a natural-number literal, whose value we extract as `number`.
      | [_, Lean.Expr.lit (Lean.Literal.natVal number), _] => Option.some number
      -- Any other argument arrangement is unsupported by this function.
      | _ => Option.none
    else
      Option.none


-- INPUT: Lean's internal expression for a list such as [2, 2].
-- OUTPUT: `some [2, 2]` if every element can be read; otherwise `none`.
--
-- LEAN-SPECIFIC: A list is represented as `nil` (empty) or `cons`
-- (first item + remaining list). This function reads the first item,
-- then repeats on the rest. That's why it calls itself.
--
-- EXAMPLE: source-code shape `[2, 2]` is conceptually represented as:
--   List.cons 2 (List.cons 2 List.nil)
--
-- Each `cons` is one item plus the rest of the list. The numbers and
-- list structure are themselves stored inside Lean's `Expr` objects.
--
-- NEW SYNTAX BEFORE WE USE IT:
-- `partial`: we wrote a recursive function, and are not asking Lean's
--   termination checker to prove it always finishes.
-- `do`: lets us write several dependent steps in sequence.
-- `←` with an `Option` result: take the value out of `Option.some`;
--   if the result is `Option.none`, stop and return `Option.none`.
-- This is like a C# method returning null and its caller immediately
-- returning null too, instead of continuing with a missing value.

private partial def readDimensions (expression : Lean.Expr) : Option (List Nat) := do
  -- If the list is empty, there are no more dimensions to read.
  -- `return []` here succeeds with an empty list (`Option.some []`).
  if expression.isAppOf ``List.nil then
    return []

  -- Otherwise, see whether the expression represents a nonempty list.
  if expression.isAppOf ``List.cons then
    match expression.getAppArgs.toList with
    -- The three arguments are:
    -- 1. The list's element type (ignored).
    -- 2. Its first item, still represented as a Lean expression.
    -- 3. The rest of the list, also represented as a Lean expression.
    | [_, firstDimensionExpression, remainingDimensionsExpression] =>
      -- Read the first number. Stop with none if it cannot be read.
      let firstDimension ← readNaturalNumber firstDimensionExpression
      -- Read the remainder using this same function (recursion).
      let remainingDimensions ← readDimensions remainingDimensionsExpression
      -- Rebuild an ordinary list of numbers from the parts we read.
      return List.cons firstDimension remainingDimensions
    | _ => Option.none

  -- Neither empty-list nor nonempty-list expression? Unsupported.
  Option.none


-- ================================================================
-- SECTION 4: Convert a Lean tensor TYPE into MLIR type TEXT.
-- ================================================================
--
-- PURPOSE:
-- `TypedTensor [2, 2] Dtype.float32` is a Lean type.
-- `tensor<2x2xf32>` is how we describe the same tensor type in MLIR text.
-- We need this text to write the StableHLO operation later.
--
-- THIS IS NOT PERFORMING MATRIX MULTIPLICATION.
-- It only turns type information into a string.

-- INPUT: Lean's internal representation of a declared type.
-- OUTPUT: The MLIR type string, or failure if not supported by this POC.
--
-- EXAMPLE:
--   Input: an Expr for `LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32`
--   Output: `Option.some "tensor<2x2xf32>"`
--
-- This function assumes the type's structure looks like:
--   TypedTensor(shape, elementType)
-- It refuses other types instead of guessing what they mean.

private def readMlirTensorType (expression : Lean.Expr) : Option String := do

  -- Is this type an application of our TypedTensor constructor?
  -- If not, give up. In an `Option` computation, `failure` means none.
  if not (expression.isAppOf ``LtomPoc.TypedTensor) then
    failure

  -- TypedTensor has two arguments: shape and element type.
  -- The `[a, b]` pattern matches a list containing exactly TWO items.
  -- Those names become new local variables containing the two Expr objects.
  match expression.getAppArgs.toList with
  | [dimensionsExpression, elementTypeExpression] =>
    -- Convert the shape expression into an ordinary List Nat.
    -- If the dimensions cannot be read, this function returns none here.
    let dimensions ← readDimensions dimensionsExpression

    -- A reference to a named declaration is represented by `Expr.const`.
    -- This match extracts its name into `elementTypeName` and ignores the
    -- other field (`_`). Here we expect the named float32 declaration.
    match elementTypeExpression with
    | Lean.Expr.const elementTypeName _ =>
      -- The POC currently supports only float32 elements.
      if elementTypeName == ``TensorLib.Dtype.float32 then
        -- Example: [2, 2] becomes ["2", "2"], then "2x2".
        -- `map` applies `toString` to each list item.
        -- `intercalate` joins strings with "x" between them.
        let dimensionsAsStrings := dimensions.map toString
        let shapeText := String.intercalate "x" dimensionsAsStrings
        -- `++` joins strings. `return` wraps the result in Option.some.
        return "tensor<" ++ shapeText ++ "xf32>"
      else
        Option.none
    | _ => Option.none
  | _ => Option.none


-- We need three types for matmul: left input, right input, and result.
-- Keep them together instead of passing around three unrelated strings.
-- `structure` is like a small C# class or C++ struct with named fields.
-- These fields hold TYPE STRINGS, not tensors or numeric values.

private structure MatmulTypes where
  leftOperandType : String
  rightOperandType : String
  resultType : String


-- INPUT: The type of the entire function `matmul2x2`.
-- OUTPUT: Three MLIR type strings for its inputs and output.
--
-- LEAN-SPECIFIC: A function type with two parameters is represented
-- internally by nested `forallE` expressions. We don't need to change
-- those expressions; we only read the declared parameter/result types.
--
-- For a C++/C# programmer, think "read a method signature":
--   matmul2x2(left : TensorType, right : TensorType) : TensorType
--
-- Lean stores this type as two nested function-parameter nodes:
--   forallE(leftParameterType, forallE(rightParameterType, resultType))
--
-- `forallE` is the NAME of a Lean expression variant, not a loop.
-- Each `forallE` has extra fields for parameter name and metadata. Our
-- pattern uses `_` to ignore them; we only need the three types.

private def readFunctionSignature (functionType : Lean.Expr) : Option MatmulTypes := do
  match functionType with
  -- Only accept a function type with exactly two parameters.
  -- Pattern matching binds its parameter/result types to three names.
  | Lean.Expr.forallE _ leftParameterType
      (Lean.Expr.forallE _ rightParameterType resultType _) _ =>
    -- Translate each of the three Lean types to an MLIR type string.
    -- `←` stops with none if any translation fails.
    let leftOperandType ← readMlirTensorType leftParameterType
    let rightOperandType ← readMlirTensorType rightParameterType
    let outputType ← readMlirTensorType resultType
    -- `{ field := value }` creates a MatmulTypes record.
    -- These are FIELD ASSIGNMENTS, not type definitions.
    return {
      leftOperandType := leftOperandType
      rightOperandType := rightOperandType
      resultType := outputType
    }
  | _ => failure


-- ================================================================
-- SECTION 5: Generate StableHLO text and WRITE the .mlir file.
-- ================================================================
--
-- PURPOSE:
-- This is the actual output we care about.
-- The earlier functions gave us type strings. Here we use them in a
-- small StableHLO template representing a matrix multiplication.
--
-- Before: the old POC printed text into a log, then used Python to
-- search the log and reconstruct the .mlir file.
-- Now: the compiler pass writes the complete text DIRECTLY to the file.

-- INPUT: The three tensor types read from the Lean declaration.
-- OUTPUT: Creates `artifacts/matmul.mlir` on disk.
--
-- `CompilerM Unit` is a Lean compiler API type: this operation runs
-- *inside the compiler* and returns no interesting value to its caller.
-- Conceptually, `Unit` is like a `void` return in C# or C++.
-- Unlike the earlier `Option` functions, this one can perform compiler
-- actions such as writing a file and reporting diagnostic messages.
-- `do` again lets us write those actions in sequence.

private def emitStableHLO (types : MatmulTypes) : Lean.Compiler.LCNF.CompilerM Unit := do
  let leftType := types.leftOperandType
  let rightType := types.rightOperandType
  let outputType := types.resultType

  -- `let` introduces a local variable, as in C# or C++.
  -- Each list entry below is one line of the output file.
  -- `stablehlo.dot` is the StableHLO operation for matrix multiplication
  -- in the narrow case handled by this POC.
  let lines : List String := [
    "module {",
    "  func.func @matmul(%x: " ++ leftType ++ ", %y: " ++ rightType ++ ") -> " ++ outputType ++ " {",
    "    %z = stablehlo.dot %x, %y : (" ++ leftType ++ ", " ++ rightType ++ ") -> " ++ outputType,
    "    return %z : " ++ outputType,
    "  }",
    "}"
  ]

  -- Join the lines into one string with real line breaks.
  let stablehloText := String.intercalate "\n" lines ++ "\n"

  -- The runner starts in the thesis project root, so this path is
  -- relative to that root, not relative to LtomPocSupport.lean.
  let outputPath : System.FilePath :=
    "experiments/tlib_to_mlir_direct_poc/artifacts/matmul.mlir"

  -- This is the ONE line responsible for writing the StableHLO file.
  -- `IO.FS.writeFile` writes a string to a disk file.
  -- It creates an IO operation; the compiler pass uses `liftM` to run it.
  -- `<|` means "apply the function on the left to everything on the right".
  -- So conceptually this is: liftM (IO.FS.writeFile outputPath stablehloText)
  -- (No StableHLO is recovered from a log file.)
  liftM <| IO.FS.writeFile outputPath stablehloText

  -- Keep a diagnostic message, but not the StableHLO text itself.
  Lean.logInfo m!"[POC] StableHLO written directly to matmul.mlir"


-- ================================================================
-- SECTION 6: Recognize the tagged matrix multiplication CALL.
-- ================================================================
--
-- PURPOSE:
-- We should not generate StableHLO just because a function named
-- matmul2x2 exists. We want to detect a CALL to that marked function.
-- Lean's early internal code representation (LCNF) contains those calls.
--
-- For a matching call, this function:
--   1. Checks that the called function has our `ltom_poc` tag.
--   2. Reads its declared tensor input and output types.
--   3. Checks that the call has exactly two inputs.
--   4. Calls `emitStableHLO` to write the .mlir file.

-- The parameters here are data ABOUT a compiled call:
-- `Lean.Name` is Lean's representation of a declaration/variable name.
-- `Array` is a growable sequence (like C# List<T> or C++ vector<T>).
-- `LCNF.Arg ...` means a compiler argument, not an actual TensorLib tensor.
-- `Purity.pure` identifies which LCNF code category these arguments use;
-- you do not need that distinction to understand this POC's call detection.

private def inspectFunctionCall
    (functionName : Lean.Name)
    (operands : Array (Lean.Compiler.LCNF.Arg Lean.Compiler.LCNF.Purity.pure))
    (resultName : Lean.Name) : Lean.Compiler.LCNF.CompilerM Unit := do

  -- `CompilerM` also uses `do` and `←`, but here they get values from
  -- compiler operations instead of unwrapping Option.some.
  -- `getEnv` asks the compiler for its table of known declarations.
  -- That table includes the `ltom_poc` tags registered earlier.
  let environment ← Lean.getEnv

  -- Ignore calls to functions that we did not mark `@[ltom_poc]`.
  -- If the tag is absent, this function simply does nothing.
  if ltomPocAttr.hasTag environment functionName then

    -- Look up the *declared* type of that function, not its actual values.
    let declaration ← Lean.getConstInfo functionName

    -- `readFunctionSignature` returns `Option MatmulTypes`.
    -- `Option.some types` matches the success case AND extracts `types`.
    -- `Option.none` is handled at the bottom of this match.
    match readFunctionSignature declaration.type with
    | Option.some types =>
      -- The call must have exactly TWO arguments.
      -- The two names below are filled in by the pattern match.
      match operands.toList with
      | [leftOperand, rightOperand] =>
        -- `m!"...{value}..."` creates a diagnostic message with variables
        -- inserted (similar to C# $"...{value}...").
        -- These lines are diagnostics; generated MLIR goes to a file.
        Lean.logInfo m!"[POC] call={functionName}"
        Lean.logInfo m!"[POC] operand0={leftOperand.toExpr} type={types.leftOperandType}"
        Lean.logInfo m!"[POC] operand1={rightOperand.toExpr} type={types.rightOperandType}"
        Lean.logInfo m!"[POC] result={resultName} type={types.resultType}"
        -- Now we have recognized the call AND its tensor types.
        -- Generate and write the .mlir file.
        emitStableHLO types
      | _ =>
        Lean.logError m!"[POC_ERROR] Expected 2 LCNF operands, found {operands.size}"
    | Option.none =>
      Lean.logError m!"[POC_ERROR] Cannot read tensor types from {declaration.type}"


-- ================================================================
-- SECTION 7: Connect the call detector to the Lean compiler.
-- ================================================================
--
-- PURPOSE:
-- We have defined how to inspect ONE call. Now we need Lean to actually
-- invoke that inspection while it compiles Main.lean.
--
-- This section is Lean-compiler-specific. You can understand the project's
-- pipeline without knowing all the constructors used by Lean here.

-- ORDER OF CALLS DURING COMPILATION (read from top to bottom):
--   Lean compiler
--     -> our registered ltomPocPass
--     -> inspectCalls                 (visit the code)
--     -> inspectFunctionCall          (check one call)
--     -> readFunctionSignature        (read its type)
--        -> readMlirTensorType        (read tensor type)
--           -> readDimensions         (read shape)
--              -> readNaturalNumber   (read each number)
--     -> emitStableHLO                (write the file)
--
-- This section examines *LCNF*, the compiler's intermediate instructions.
-- That is DIFFERENT from `Lean.Expr`, which the earlier functions used to
-- inspect source-level types. We need both because calls are seen in LCNF,
-- while declaration types are accessed as Expr trees.
--
-- `code.forM fun instruction => do` is a loop over instructions.
-- `fun instruction =>` defines the unnamed function to run for EACH one.
-- It is similar to C# `foreach (var instruction in code) { ... }`.
--
-- `match` works just like the earlier Expr matches, except now we match
-- LCNF INSTRUCTION VARIANTS rather than expression variants.
-- `Code Purity.pure` is Lean's internal representation of the code we are
-- visiting; it is not source code text or a normal C++ container.
-- `pure ()` below means "do nothing and succeed" in this compiler operation.
-- `()` is a Unit value, like a void-like result.

private def inspectCalls
    (code : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM Unit :=

  code.forM fun instruction => do
    match instruction with
    -- This is a "let" instruction: it has a binding and more code.
    -- We need the binding; `_` discards the field we do not use here.
    | Lean.Compiler.LCNF.Code.let binding _ =>
      -- Look inside the binding to see what value it computes.
      match binding.value with
      -- This case is a call to a known named function.
      -- Extract: its name, arguments (`operands`), and ignore two fields.
      | Lean.Compiler.LCNF.LetValue.const functionName _ operands _ =>
        -- `binderName` is where the call's result is assigned.
        inspectFunctionCall functionName operands binding.binderName
      -- This binding is not the kind of call we are looking for.
      | _ => pure ()
    -- This is some other kind of instruction; skip it.
    | _ => pure ()


-- Give our inspection a name so the compiler can run it as a pass.
-- We return the original declaration unchanged: this POC observes
-- the compiler's code and writes an .mlir file; it does not rewrite LCNF.

-- `Pass` is Lean's representation of a compiler pass.
-- The single backtick in `ltomPocPass` constructs a Lean *name*;
-- it does not call the function. This is different from a quoted string.
-- `mkPerDeclaration` means run the supplied function on each declaration
-- (roughly each compiled function), one at a time.
-- `fun declaration => do` defines that per-declaration function.
private def ltomPocPass : Lean.Compiler.LCNF.Pass :=
  Lean.Compiler.LCNF.Pass.mkPerDeclaration
    `ltomPocPass
    Lean.Compiler.LCNF.Phase.base
    fun declaration => do
      -- Walk the instructions in this declaration, calling inspectCalls.
      match declaration.value with
      | .code body => inspectCalls body
      | .extern _ => pure ()
      -- Return the SAME declaration. We are observing it, not modifying it.
      return declaration


-- LEAN-SPECIFIC: `@[cpass]` registers an installer with Lean's compiler.
-- The installer tells the compiler where our pass should run.
-- `installAfter ... init` places it near the start of LCNF compilation,
-- when the matrix-multiplication call is still visible.
-- `Phase.base` selects the compiler phase, and `init` names an existing pass.
-- `fun _ => ltomPocPass` means "given the installer argument (not needed),
-- return our pass". The `_` says to ignore that argument.

@[cpass] meta def installLtomPoc : Lean.Compiler.LCNF.PassInstaller :=
  Lean.Compiler.LCNF.PassInstaller.installAfter
    Lean.Compiler.LCNF.Phase.base
    `init
    (fun _ => ltomPocPass)
