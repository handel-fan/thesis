import Lean
import LtomPocSupport

set_option trace.Compiler.result true

@[noinline]
def probe
    (a : LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32) :
    LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32 :=
  a
