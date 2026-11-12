import LtomPocSupport

open TensorLib
open LtomPoc

-- This annotation tells our compiler pass to recognize calls to matmul2x2.
-- noinline helps keep the call visible in early LCNF.
@[ltom_poc, noinline]
def matmul2x2
    (left : TypedTensor [2, 2] Dtype.float32)
    (right : TypedTensor [2, 2] Dtype.float32) : TypedTensor [2, 2] Dtype.float32 :=
  let tensorResult := Tensor.Ufunc.matmul left.raw right.raw
  let resultTensor : Tensor := get! tensorResult
  { raw := resultTensor }

def main : IO Unit := do
  let flatLeftTensor : Tensor := Tensor.ofFloat32List! [1, 2, 3, 4]
  let leftTensor : Tensor := Tensor.reshape! flatLeftTensor (Shape.mk [2, 2])
  let left : TypedTensor [2, 2] Dtype.float32 := { raw := leftTensor }

  let flatRightTensor : Tensor := Tensor.ofFloat32List! [5, 6, 7, 8]
  let rightTensor : Tensor := Tensor.reshape! flatRightTensor (Shape.mk [2, 2])
  let right : TypedTensor [2, 2] Dtype.float32 := { raw := rightTensor }

  let result := matmul2x2 left right

  let expected : Tensor.Format.Tree Float32 := Tensor.Format.Tree.node [
    Tensor.Format.Tree.root [19.0, 22.0],
    Tensor.Format.Tree.root [43.0, 50.0]
  ]
  let actual := Tensor.toFloat32Tree! result.raw

  if actual != expected then
    throw (IO.userError "incorrect TensorLib matmul result")

  IO.println "TENSORLIB_OK"
