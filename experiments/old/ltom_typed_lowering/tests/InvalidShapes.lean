import LtomTypedLowering.Examples.Add

open TensorLib
open LtomTypedLowering

-- This file MUST fail to type-check: the second parameter has the wrong shape.
def shouldNotCompile (x : TypedTensor [2,3] .float32)
    (wrong : TypedTensor [3,2] .float32) : Err (TypedTensor [2,3] .float32) :=
  ltomAdd2x3 x wrong
