import Lean

namespace TensorTagProbe

-- A shorter name for an LCNF variable assignment.
private abbrev Binding :=
  Lean.Compiler.LCNF.LetDecl Lean.Compiler.LCNF.Purity.pure

-- Information associated with one tensor.
private structure TensorInfo where
  tensor : Lean.Expr
  rows : Lean.Expr
  cols : Lean.Expr
  dtype : Lean.Expr

-- Look up a variable assignment.
-- Example: _x.1 -> 2
private def resolve
    (assignments : List (Lean.Expr × Lean.Expr))
    (argument : Lean.Expr) : Lean.Expr :=
  match assignments.find? (fun (pair : Lean.Expr × Lean.Expr) => pair.1 == argument) with
  | some pair => pair.2
  | none => argument

-- Called by forM for each instruction.
-- StateM maintains a list of assignments while traversing.
private def saveInstruction
    (instruction : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure)
    : StateM (List Binding) Unit := do
  match instruction with
  | Lean.Compiler.LCNF.Code.let binding _ =>
    modify (fun (saved : List Binding) => binding :: saved)
  | _ =>
    pure ()

-- Collect every variable assignment from the LCNF body.
private def collectBindings
    (code : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure)
    : List Binding :=

  let traversal : StateM (List Binding) Unit :=
    Lean.Compiler.LCNF.Code.forM
      (m := StateM (List Binding)) code saveInstruction

  let (_, backwards) := traversal.run []
  backwards.reverse

-- Given a tensor variable, find its tensorTag call.
-- Recover its dimensions and dtype from the assignments.
private def findTensor
    (bindings : List Binding)
    (assignments : List (Lean.Expr × Lean.Expr))
    (tensor : Lean.Expr) : Option TensorInfo :=

  match bindings.find? (fun (binding : Binding) =>
      Lean.Expr.fvar binding.fvarId == tensor) with
  | none => none
  | some binding =>
    match binding.value with
    | Lean.Compiler.LCNF.LetValue.const functionName _ arguments _ =>
      if functionName == `tensorTag then
        match arguments.toList with
        | [rowArg, colArg, dtypeArg, _tensorArg] =>
          some {
            tensor := tensor
            rows := resolve assignments rowArg.toExpr
            cols := resolve assignments colArg.toExpr
            dtype := resolve assignments dtypeArg.toExpr
          }
        | _ => none
      else
        none
    | _ => none

-- Main inspection function.
-- First collect bindings, then inspect function calls.
private def inspectCode
    (code : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  let bindings : List Binding := collectBindings code

  -- Create the variable-to-value lookup table.
  let assignments : List (Lean.Expr × Lean.Expr) :=
    bindings.map (fun (binding : Binding) =>
      (Lean.Expr.fvar binding.fvarId, binding.value.toExpr))

  -- Inspect the assignments in order.
  for binding in bindings do
    match binding.value with
    | Lean.Compiler.LCNF.LetValue.const functionName _ arguments _ =>

      if functionName == `tensorTag then
        let tensor : Lean.Expr := Lean.Expr.fvar binding.fvarId

        match findTensor bindings assignments tensor with
        | some info =>
          Lean.logInfo m!"TAGGED {binding.binderName}: rows={info.rows} cols={info.cols} dtype={info.dtype}"
        | none =>
          Lean.logError "tensorTag metadata not found"

      else if functionName == `matmul2x2 then
        match arguments.toList with
        | [left, right] =>
          Lean.logInfo m!"MATMUL result={binding.binderName}"

          match findTensor bindings assignments left.toExpr with
          | some info =>
            Lean.logInfo m!"LEFT: rows={info.rows} cols={info.cols} dtype={info.dtype}"
          | none =>
            Lean.logError "LEFT tensor metadata not found"

          match findTensor bindings assignments right.toExpr with
          | some info =>
            Lean.logInfo m!"RIGHT: rows={info.rows} cols={info.cols} dtype={info.dtype}"
          | none =>
            Lean.logError "RIGHT tensor metadata not found"

        | _ =>
          Lean.logError "matmul2x2 did not have two arguments"

      else
        pure ()

    | _ =>
      pure ()

-- Inspect one compiled declaration and return it unchanged.
private def inspectDeclaration
    (declaration : Lean.Compiler.LCNF.Decl Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM
        (Lean.Compiler.LCNF.Decl Lean.Compiler.LCNF.Purity.pure) := do

  declaration.value.forCodeM inspectCode
  return declaration

-- Construct the pass. Main.lean registers it.
def tensorTagPass : Lean.Compiler.LCNF.Pass :=
  Lean.Compiler.LCNF.Pass.mkPerDeclaration
    `tensorTagPass
    Lean.Compiler.LCNF.Phase.base
    inspectDeclaration

end TensorTagProbe
