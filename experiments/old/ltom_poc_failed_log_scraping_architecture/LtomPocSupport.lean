import Lean
import TensorLib.Ufunc

open Lean
open Lean.Compiler.LCNF

namespace LtomPoc

-- A wrapper that puts a tensor's dimensions and element type in its Lean type.
-- The `raw` field contains the underlying TensorLib tensor.
structure TypedTensor (dimensions : List Nat) (elementType : TensorLib.Dtype) where
  raw : TensorLib.Tensor

end LtomPoc

-- Allows functions in Main.lean to be marked with @[ltom_poc].
initialize ltomPocAttr : TagAttribute ←
  registerTagAttribute `ltom_poc "Find this function during early LCNF compilation"

-- Read a natural number from Lean's internal expression representation.
-- Lean may store 2 either as a literal or as OfNat.ofNat applied to 2.
private def readNaturalNumber (expression : Expr) : Option Nat :=
  match expression with
  | Expr.lit (Literal.natVal number) =>
    Option.some number
  | _ =>
    if expression.isAppOf ``OfNat.ofNat then
      -- The arguments are: element type, number, and proof.
      match expression.getAppArgs.toList with
      | [_, Expr.lit (Literal.natVal number), _] => Option.some number
      | _ => Option.none
    else
      Option.none

-- Turn Lean's internal representation of [2, 2] into a List Nat.
private partial def readDimensions (expression : Expr) : Option (List Nat) := do
  if expression.isAppOf ``List.nil then
    return []

  if expression.isAppOf ``List.cons then
    -- List.cons receives an element type, a first element, and a rest list.
    match expression.getAppArgs.toList with
    | [_, firstDimensionExpression, remainingDimensionsExpression] =>
      let firstDimension ← readNaturalNumber firstDimensionExpression
      let remainingDimensions ← readDimensions remainingDimensionsExpression
      return List.cons firstDimension remainingDimensions
    | _ => Option.none

  Option.none

-- Translate the Lean type TypedTensor [2, 2] Dtype.float32
-- into the MLIR type string tensor<2x2xf32>.
private def readMlirTensorType (expression : Expr) : Option String := do
  if not (expression.isAppOf ``LtomPoc.TypedTensor) then
    failure

  -- TypedTensor receives exactly two arguments: dimensions and element type.
  match expression.getAppArgs.toList with
  | [dimensionsExpression, elementTypeExpression] =>
    let dimensions ← readDimensions dimensionsExpression
    match elementTypeExpression with
    | Expr.const elementTypeName _ =>
      if elementTypeName == ``TensorLib.Dtype.float32 then
        let dimensionsAsStrings := dimensions.map toString
        let shapeText := String.intercalate "x" dimensionsAsStrings
        return "tensor<" ++ shapeText ++ "xf32>"
      else
        Option.none
    | _ => Option.none
  | _ => Option.none

-- The three types we need for one two-input matrix multiplication.
private structure MatmulTypes where
  leftOperandType : String
  rightOperandType : String
  resultType : String

-- Read the types from a function declaration such as:
--   TypedTensor [2, 2] Dtype.float32 →
--   TypedTensor [2, 2] Dtype.float32 →
--   TypedTensor [2, 2] Dtype.float32
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

-- The existing run.fish script replaces @@NL@@ with real newlines.
-- This keeps the emitted MLIR on a single compiler log line.
private def emitStableHLO (types : MatmulTypes) : CompilerM Unit := do
  let leftType := types.leftOperandType
  let rightType := types.rightOperandType
  let outputType := types.resultType

  let lines : List String := [
    "module {",
    "  func.func @matmul(%x: " ++ leftType ++ ", %y: " ++ rightType ++ ") -> " ++ outputType ++ " {",
    "    %z = stablehlo.dot %x, %y : (" ++ leftType ++ ", " ++ rightType ++ ") -> " ++ outputType,
    "    return %z : " ++ outputType,
    "  }",
    "}"
  ]
  let mlir := String.intercalate "@@NL@@" lines
  logInfo m!"[SHLO] {mlir}"

-- Associate the two LCNF call operands with their declared parameter types.
private def inspectFunctionCall
    (functionName : Name)
    (operands : Array (Arg Purity.pure))
    (resultName : Name) : CompilerM Unit := do

  let environment ← getEnv
  if ltomPocAttr.hasTag environment functionName then
    let declaration ← getConstInfo functionName
    match readFunctionSignature declaration.type with
    | Option.some types =>
      match operands.toList with
      | [leftOperand, rightOperand] =>
        logInfo m!"[POC] call={functionName}"
        logInfo m!"[POC] operand0={leftOperand.toExpr} type={types.leftOperandType}"
        logInfo m!"[POC] operand1={rightOperand.toExpr} type={types.rightOperandType}"
        logInfo m!"[POC] result={resultName} type={types.resultType}"
        emitStableHLO types
      | _ =>
        logError m!"[POC_ERROR] Expected 2 LCNF operands, found {operands.size}"
    | Option.none =>
      logError m!"[POC_ERROR] Cannot read tensor types from {declaration.type}"

-- Visit instructions in the early LCNF representation of a declaration.
private def inspectCalls (code : Code Purity.pure) : CompilerM Unit :=
  code.forM fun instruction => do
    match instruction with
    | Code.let binding _ =>
      match binding.value with
      | LetValue.const functionName _ operands _ =>
        inspectFunctionCall functionName operands binding.binderName
      | _ => pure ()
    | _ => pure ()

-- Run the inspection on each declaration without modifying Lean's IR.
private def ltomPocPass : Pass :=
  Pass.mkPerDeclaration `ltomPocPass Phase.base fun declaration => do
    declaration.value.forCodeM inspectCalls
    return declaration

-- Insert our pass immediately after Lean first generates LCNF.
@[cpass] meta def installLtomPoc : PassInstaller :=
  PassInstaller.installAfter Phase.base `init (fun _ => ltomPocPass)
