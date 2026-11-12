import TensorLib

namespace LtomTypedLowering
open TensorLib

/-
 A proof-carrying view of an ordinary TensorLib tensor. The shape and dtype
 are in the *Lean type*, and the fields prove the wrapped runtime tensor has
 those properties. The MLIR frontend never reads `raw` or these proofs.
-/
structure TypedTensor (dims : List Nat) (dtype : Dtype) where
  raw : Tensor
  shapeValid : (raw.shape.val == dims) = true
  dtypeValid : (raw.dtype == dtype) = true

namespace TypedTensor

-- The only constructor used by this experiment: validate a real TensorLib value.
def check {dims : List Nat} {dtype : Dtype} (raw : Tensor) : Err (TypedTensor dims dtype) :=
  if hs : (raw.shape.val == dims) = true then
    if hd : (raw.dtype == dtype) = true then
      .ok ⟨raw, hs, hd⟩
    else
      .error "TypedTensor: dtype mismatch"
  else
    .error "TypedTensor: shape mismatch"

end TypedTensor
end LtomTypedLowering
