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
- You do not need to know Lean's compiler internals before reading this.
  The numbered sections describe the job of each group of functions.

READING GUIDE:
1. Read Main.lean first.
2. Here, skim the numbered section headings before reading the code.
3. Sections 3-5 contain technical details of Lean's internal expression
   representation. It's enough to understand their input/output at first.
-/

-- These imports provide the Lean compiler's APIs and TensorLib's tensor types.
import Lean
import TensorLib.Ufunc

-- Convenience: use shorter names for the Lean compiler's data types.
open Lean
open Lean.Compiler.LCNF


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
initialize ltomPocAttr : TagAttribute ←
  registerTagAttribute `ltom_poc "Find this function during early LCNF compilation"


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
private def readNaturalNumber (expression : Expr) : Option Nat :=
  match expression with
  | Expr.lit (Literal.natVal number) =>
    Option.some number
  | _ =>
    -- Lean sometimes represents the number via `OfNat.ofNat` instead
    -- of a direct numeric literal. Handle that common case too.
    if expression.isAppOf ``OfNat.ofNat then
      match expression.getAppArgs.toList with
      | [_, Expr.lit (Literal.natVal number), _] => Option.some number
      | _ => Option.none
    else
      Option.none

-- INPUT: Lean's internal expression for a list such as [2, 2].
-- OUTPUT: `some [2, 2]` if every element can be read; otherwise `none`.
--
-- LEAN-SPECIFIC: A list is represented as `nil` (empty) or `cons`
-- (first item + remaining list). This function reads the first item,
-- then repeats on the rest. That's why it calls itself.
private partial def readDimensions (expression : Expr) : Option (List Nat) := do
  if expression.isAppOf ``List.nil then
    return []

  if expression.isAppOf ``List.cons then
    match expression.getAppArgs.toList with
    | [_, firstDimensionExpression, remainingDimensionsExpression] =>
      let firstDimension ← readNaturalNumber firstDimensionExpression
      let remainingDimensions ← readDimensions remainingDimensionsExpression
      return List.cons firstDimension remainingDimensions
    | _ => Option.none

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
private def readMlirTensorType (expression : Expr) : Option String := do

  -- The POC only recognizes our custom TypedTensor type.
  if not (expression.isAppOf ``LtomPoc.TypedTensor) then
    failure

  -- TypedTensor has two arguments: shape and element type.
  match expression.getAppArgs.toList with
  | [dimensionsExpression, elementTypeExpression] =>
    let dimensions ← readDimensions dimensionsExpression

    match elementTypeExpression with
    | Expr.const elementTypeName _ =>
      -- The POC currently supports only float32 elements.
      if elementTypeName == ``TensorLib.Dtype.float32 then
        let dimensionsAsStrings := dimensions.map toString
        let shapeText := String.intercalate "x" dimensionsAsStrings
        return "tensor<" ++ shapeText ++ "xf32>"
      else
        Option.none
    | _ => Option.none
  | _ => Option.none


-- We need three types for matmul: left input, right input, and result.
-- Keep them together instead of passing around three unrelated strings.
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
private def readFunctionSignature (functionType : Expr) : Option MatmulTypes := do
  match functionType with
  | Expr.forallE _ leftParameterType
      (Expr.forallE _ rightParameterType resultType _) _ =>
    let leftOperandType ← readMlirTensorType leftParameterType
    let rightOperandType ← readMlirTensorType rightParameterType
    let outputType ← readMlirTensorType resultType
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
private def emitStableHLO (types : MatmulTypes) : CompilerM Unit := do
  let leftType := types.leftOperandType
  let rightType := types.rightOperandType
  let outputType := types.resultType

  -- Each list entry is one line of the output file.
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
  -- LEAN-SPECIFIC: `IO.FS.writeFile` writes a string to a disk file.
  -- `liftM` allows the compiler-pass code to perform that IO action.
  liftM <| IO.FS.writeFile outputPath stablehloText

  -- Keep a diagnostic message, but not the StableHLO text itself.
  logInfo m!"[POC] StableHLO written directly to matmul.mlir"


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

private def inspectFunctionCall
    (functionName : Name)
    (operands : Array (Arg Purity.pure))
    (resultName : Name) : CompilerM Unit := do

  -- The compiler's `environment` stores information about declarations,
  -- including the tags we attached to functions earlier.
  let environment ← getEnv

  -- Ignore calls to functions that we did not mark.
  if ltomPocAttr.hasTag environment functionName then

    -- Get the type declared for this function (not its runtime values).
    let declaration ← getConstInfo functionName
    match readFunctionSignature declaration.type with
    | Option.some types =>
      match operands.toList with
      | [leftOperand, rightOperand] =>
        -- These lines are diagnostics; generated MLIR goes to a file.
        logInfo m!"[POC] call={functionName}"
        logInfo m!"[POC] operand0={leftOperand.toExpr} type={types.leftOperandType}"
        logInfo m!"[POC] operand1={rightOperand.toExpr} type={types.rightOperandType}"
        logInfo m!"[POC] result={resultName} type={types.resultType}"
        emitStableHLO types
      | _ =>
        logError m!"[POC_ERROR] Expected 2 LCNF operands, found {operands.size}"
    | Option.none =>
      logError m!"[POC_ERROR] Cannot read tensor types from {declaration.type}"


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

-- Walk through the compiler's LCNF instructions for one function.
-- We only care about an instruction that calls a function (`LetValue.const`).
-- Everything else is ignored.
private def inspectCalls (code : Code Purity.pure) : CompilerM Unit :=
  code.forM fun instruction => do
    match instruction with
    | Code.let binding _ =>
      match binding.value with
      | LetValue.const functionName _ operands _ =>
        inspectFunctionCall functionName operands binding.binderName
      | _ => pure ()
    | _ => pure ()

-- Give our inspection a name so the compiler can run it as a pass.
-- We return the original declaration unchanged: this POC observes
-- the compiler's code and writes an .mlir file; it does not rewrite LCNF.
private def ltomPocPass : Pass :=
  Pass.mkPerDeclaration `ltomPocPass Phase.base fun declaration => do
    declaration.value.forCodeM inspectCalls
    return declaration

-- LEAN-SPECIFIC: `@[cpass]` registers this pass with Lean's compiler.
-- `installAfter ... init` places it near the start of LCNF compilation,
-- when the matrix-multiplication call is still visible.
@[cpass] meta def installLtomPoc : PassInstaller :=
  PassInstaller.installAfter Phase.base `init (fun _ => ltomPocPass)
