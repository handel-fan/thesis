import TensorLib
open TensorLib

def invalid : Err Tensor :=
  Tensor.matmul
    (Tensor.zeros .float32 (Shape.mk [2, 3]))
    (Tensor.zeros .float32 (Shape.mk [4, 2]))

#check invalid
