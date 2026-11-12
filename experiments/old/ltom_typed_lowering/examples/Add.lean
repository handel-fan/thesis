import LtomTypedLowering.LtomSupport
import LtomTypedLowering.TypedTensor

open TensorLib
namespace LtomTypedLowering

-- These two functions are opaque to LTOM: their implementations must NOT be
-- traversed. Their typed interfaces, not their bodies, determine MLIR types.
@[ltom_handel, noinline]
def ltomAdd2x3 (x y : TypedTensor [2, 3] .float32) :
    Err (TypedTensor [2, 3] .float32) := do
  let raw ← Tensor.Ufunc.add x.raw y.raw
  TypedTensor.check raw

@[ltom_handel, noinline]
def ltomAdd2x2 (x y : TypedTensor [2, 2] .float32) :
    Err (TypedTensor [2, 2] .float32) := do
  let raw ← Tensor.Ufunc.add x.raw y.raw
  TypedTensor.check raw

private def expectOk {α : Type} (e : Err α) : IO α :=
  match e with
  | .ok x => pure x
  | .error msg => throw (IO.userError msg)

-- Test inputs here intentionally match the constants in EmitStableHLO.lean.
-- Both TensorLib and StableHLO must independently pass their expected values.
def runAddTests : IO Unit := do
  let x ← expectOk (TypedTensor.check (dims := [2,3]) (dtype := .float32)
    ((Tensor.ofFloat32List! [1,2,3,4,5,6]).reshape! (Shape.mk [2,3])))
  let y ← expectOk (TypedTensor.check (dims := [2,3]) (dtype := .float32)
    ((Tensor.ofFloat32List! [10,20,30,40,50,60]).reshape! (Shape.mk [2,3])))
  let z ← expectOk (ltomAdd2x3 x y)
  unless z.raw.toFloat32Tree! ==
      TensorLib.Tensor.Format.Tree.node [
        .root [11.0,22.0,33.0], .root [44.0,55.0,66.0]] do
    throw (IO.userError "add2x3: incorrect result")
  IO.println "TENSORLIB_OK add2x3"
  let x2 ← expectOk (TypedTensor.check (dims := [2,2]) (dtype := .float32)
    ((Tensor.ofFloat32List! [1,2,3,4]).reshape! (Shape.mk [2,2])))
  let y2 ← expectOk (TypedTensor.check (dims := [2,2]) (dtype := .float32)
    ((Tensor.ofFloat32List! [5,6,7,8]).reshape! (Shape.mk [2,2])))
  let z2 ← expectOk (ltomAdd2x2 x2 y2)
  unless z2.raw.toFloat32Tree! ==
      TensorLib.Tensor.Format.Tree.node [
        .root [6.0,8.0], .root [10.0,12.0]] do
    throw (IO.userError "add2x2: incorrect result")
  IO.println "TENSORLIB_OK add2x2"

end LtomTypedLowering

def main : IO Unit := LtomTypedLowering.runAddTests
