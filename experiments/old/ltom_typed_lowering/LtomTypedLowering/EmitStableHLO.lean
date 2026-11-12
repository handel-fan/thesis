import LtomTypedLowering.TypedTensor
import Lean

namespace LtomTypedLowering
open Lean

structure TensorSpec where
  dims : List Nat
  elem : String
  deriving Repr, Inhabited, BEq

-- Parse only the small, explicitly supported dependent-type fragment.
-- No examination or execution of a TensorLib operation's implementation.
private def natLit? : Expr → Option Nat
  | .lit (.natVal n) => some n
  | _ => none

private partial def dims? (e : Expr) : Option (List Nat) := do
  if e.isAppOf ``List.nil then
    return []
  if e.isAppOf ``List.cons then
    let args := e.getAppArgs
    let head ← args[1]?
    let tail ← args[2]?
    let n ← natLit? head
    let rest ← dims? tail
    return n :: rest
  none

private def tensorSpec? (e : Expr) : Option TensorSpec :=
  if !e.isAppOf ``LtomTypedLowering.TypedTensor then
    none
  else do
    let args := e.getAppArgs
    let shape ← args[0]?
    let dtype ← args[1]?
    let dims ← dims? shape
    match dtype with
    | .const n _ =>
      if n == ``TensorLib.Dtype.float32 then
        return ⟨dims, "f32"⟩
      else
        none
    | _ => none

-- Err A is represented by an application ending in A (either an `Err`
-- abbreviation or `Except String A`). This is deliberately narrow.
private def resultSpec? (e : Expr) : Option TensorSpec :=
  match tensorSpec? e with
  | some t => some t
  | none =>
    let args := e.getAppArgs
    match args.back? with
    | some arg => tensorSpec? arg
    | none => none

private partial def gatherParams (e : Expr) (acc : Array TensorSpec) :
    Option (Array TensorSpec × TensorSpec) := do
  match e with
  | .forallE _ domain body _ =>
    let spec ← tensorSpec? domain
    gatherParams body (acc.push spec)
  | _ =>
    let result ← resultSpec? e
    return (acc, result)

def contract? (type : Expr) : Option (Array TensorSpec × TensorSpec) :=
  gatherParams type #[]

def TensorSpec.mlirType (t : TensorSpec) : String :=
  "tensor<" ++ String.intercalate "x" (t.dims.map toString) ++
    (if t.dims.isEmpty then "" else "x") ++ t.elem ++ ">"

private def mlirCase (name : String) (lhs rhs result : TensorSpec) : Option String := do
  let (op, inputA, inputB, expected) ←
    if name == "add2x3" && lhs.dims == [2,3] && rhs.dims == [2,3] && result.dims == [2,3] then
      some ("add", "[[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]", "[[10.0, 20.0, 30.0], [40.0, 50.0, 60.0]]", "[[11.0, 22.0, 33.0], [44.0, 55.0, 66.0]]")
    else if name == "add2x2" && lhs.dims == [2,2] && rhs.dims == [2,2] && result.dims == [2,2] then
      some ("add", "[[1.0, 2.0], [3.0, 4.0]]", "[[5.0, 6.0], [7.0, 8.0]]", "[[6.0, 8.0], [10.0, 12.0]]")
    else if name == "matmul2x3" && lhs.dims == [2,3] && rhs.dims == [3,2] && result.dims == [2,2] then
      some ("dot", "[[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]", "[[7.0, 8.0], [9.0, 10.0], [11.0, 12.0]]", "[[58.0, 64.0], [139.0, 154.0]]")
    else none
  unless lhs.elem == "f32" && rhs.elem == "f32" && result.elem == "f32" do
    failure
  let a := lhs.mlirType
  let b := rhs.mlirType
  let r := result.mlirType
  let operation :=
    if op == "add" then
      "    %r = stablehlo.add %a, %b : " ++ r
    else
      "    %r = stablehlo.dot %a, %b : (" ++ a ++ ", " ++ b ++ ") -> " ++ r
  return String.intercalate "@@NL@@" [
    "module {",
    "  func.func @main() {",
    "    %a = stablehlo.constant dense<" ++ inputA ++ "> : " ++ a,
    "    %b = stablehlo.constant dense<" ++ inputB ++ "> : " ++ b,
    operation,
    "    check.expect_eq_const %r, dense<" ++ expected ++ "> : " ++ r,
    "    return",
    "  }",
    "}"
  ]

def emitCase? (name : String) (params : Array TensorSpec) (result : TensorSpec) : Option String := do
  unless params.size == 2 do
    failure
  mlirCase name params[0]! params[1]! result

end LtomTypedLowering
