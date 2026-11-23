import Probe
import TensorLib.Ufunc

/-
  EXPLICIT COMPILER-PASS ACTIVATION

  `import Probe` above only loads the PASS DEFINITION.
  The `@[cpass]` below registers it with Lean's compiler.
  `installAtEnd` asks Lean to run the pass at the end of LCNF's base phase.
  `meta def` defines the registration for Lean's compiler machinery.
  Lean runs the pass automatically during compilation after registration.
-/
@[cpass] meta def installTensorTagPass : Lean.Compiler.LCNF.PassInstaller :=
  Lean.Compiler.LCNF.PassInstaller.installAtEnd
    Lean.Compiler.LCNF.Phase.base
    TensorTagProbe.tensorTagPass


set_option linter.unusedVariables false

-- Deliberately unused metadata: see whether LCNF preserves it.
@[noinline]
def tensorTag
    (rows : Nat)
    (cols : Nat)
    (dtype : TensorLib.Dtype)
    (value : TensorLib.Tensor) : TensorLib.Tensor :=
  value



@[noinline]
def matmul2x2 (left right : TensorLib.Tensor) : TensorLib.Tensor :=
  TensorLib.get! (TensorLib.Tensor.Ufunc.matmul left right)

@[noinline]
def taggedMatmul (left right : TensorLib.Tensor) : TensorLib.Tensor :=
  let a := tensorTag 2 2 TensorLib.Dtype.float32 left
  let b := tensorTag 2 2 TensorLib.Dtype.float32 right
  let product := matmul2x2 a b
  let c := tensorTag 2 2 TensorLib.Dtype.float32 product
  c

def main : IO Unit := do
  let flatLeftTensor : TensorLib.Tensor := TensorLib.Tensor.ofFloat32List! [1, 2, 3, 4]
  let left : TensorLib.Tensor := TensorLib.Tensor.reshape! flatLeftTensor (TensorLib.Shape.mk [2, 2])
  let flatRightTensor : TensorLib.Tensor := TensorLib.Tensor.ofFloat32List! [5, 6, 7, 8]
  let right : TensorLib.Tensor := TensorLib.Tensor.reshape! flatRightTensor (TensorLib.Shape.mk [2, 2])
  let result := taggedMatmul left right
  let expected : TensorLib.Tensor.Format.Tree Float32 := TensorLib.Tensor.Format.Tree.node [
    TensorLib.Tensor.Format.Tree.root [19.0, 22.0],
    TensorLib.Tensor.Format.Tree.root [43.0, 50.0]
  ]
  let actual := TensorLib.Tensor.toFloat32Tree! result
  if actual != expected then
    throw (IO.userError "incorrect TensorLib matmul result")
  IO.println "TENSORLIB_OK"
