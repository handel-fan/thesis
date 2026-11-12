import LtomTypedLowering.LtomSupport
import LtomTypedLowering.TypedTensor

open TensorLib
namespace LtomTypedLowering

@[ltom_handel, noinline]
def ltomMatmul2x3 (x : TypedTensor [2,3] .float32)
    (y : TypedTensor [3,2] .float32) : Err (TypedTensor [2,2] .float32) := do
  let raw ← Tensor.Ufunc.matmul x.raw y.raw
  TypedTensor.check raw

private def expectOk {α : Type} (e : Err α) : IO α :=
  match e with
  | .ok x => pure x
  | .error msg => throw (IO.userError msg)

def runMatmulTest : IO Unit := do
  let x ← expectOk (TypedTensor.check (dims := [2,3]) (dtype := .float32)
    ((Tensor.ofFloat32List! [1,2,3,4,5,6]).reshape! (Shape.mk [2,3])))
  let y ← expectOk (TypedTensor.check (dims := [3,2]) (dtype := .float32)
    ((Tensor.ofFloat32List! [7,8,9,10,11,12]).reshape! (Shape.mk [3,2])))
  let z ← expectOk (ltomMatmul2x3 x y)
  unless z.raw.toFloat32Tree! ==
      TensorLib.Tensor.Format.Tree.node [
        .root [58.0,64.0], .root [139.0,154.0]] do
    throw (IO.userError "matmul2x3: incorrect result")
  IO.println "TENSORLIB_OK matmul2x3"

end LtomTypedLowering

def main : IO Unit := LtomTypedLowering.runMatmulTest
