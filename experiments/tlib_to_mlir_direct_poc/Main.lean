/-
START HERE: this is the *program being compiled and tested*.

Our goal:
1. Define a function that multiplies two 2x2 TensorLib tensors.
2. Mark that function so our *compiler pass* can find its call.
3. Run the function and check the numeric answer.

Two different things happen to this file:
- During compilation, our pass notices the `matmul2x2` call and writes MLIR.
- During execution, `main` actually multiplies the matrices.

These are separate operations; producing MLIR does not run the MLIR.
-/

-- SECTION 1 / 3: Make the helper module available.
--
-- `import` makes its definitions available in this file.
-- Our runner compiles the helper into a .olean first, because that's how
-- Lean normally loads imported modules (unlike C++ #include).
import LtomPocSupport

-- No `open` statements: each library name is written in full,
-- so it is always clear which library provides it.


-- SECTION 2 / 3: Define the matrix multiplication we want to recognize.
--
-- `matmul2x2` takes two 2x2 tensors of 32-bit floating-point values.
-- It returns another 2x2 tensor.
--
-- The next line is LEAN-SPECIFIC syntax:
--   ltom_poc: Our own tag. The compiler pass will look for this function.
--   noinline: Ask Lean to keep a visible call instead of replacing it with
--             the function body too early for our pass to recognize.
@[ltom_poc, noinline]
def matmul2x2
    (left : LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32)
    (right : LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32) : LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32 :=

  -- `raw` is the actual TensorLib tensor inside our small TypedTensor wrapper.
  -- TensorLib performs the real matrix multiplication here.
  let tensorResult := TensorLib.Tensor.Ufunc.matmul left.raw right.raw

  -- `get!` extracts the successful TensorLib result. The ! form assumes
  -- success and raises an error if TensorLib returned a failure.
  let resultTensor : TensorLib.Tensor := get! tensorResult

  -- Put the result back inside our TypedTensor wrapper.
  { raw := resultTensor }


-- SECTION 3 / 3: Run a small test of the original Lean program.
--
-- `main` is the entry point used by `lean --run Main.lean`.
-- This DOES NOT execute the StableHLO file from our compiler pass.
def main : IO Unit := do

  -- Build the left 2x2 matrix:
  --   1 2
  --   3 4
  let flatLeftTensor : TensorLib.Tensor := TensorLib.Tensor.ofFloat32List! [1, 2, 3, 4]
  let leftTensor : TensorLib.Tensor := TensorLib.Tensor.reshape! flatLeftTensor (TensorLib.Shape.mk [2, 2])
  let left : LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32 := { raw := leftTensor }

  -- Build the right 2x2 matrix:
  --   5 6
  --   7 8
  let flatRightTensor : TensorLib.Tensor := TensorLib.Tensor.ofFloat32List! [5, 6, 7, 8]
  let rightTensor : TensorLib.Tensor := TensorLib.Tensor.reshape! flatRightTensor (TensorLib.Shape.mk [2, 2])
  let right : LtomPoc.TypedTensor [2, 2] TensorLib.Dtype.float32 := { raw := rightTensor }

  -- This is the call that the compiler pass is trying to detect.
  let result := matmul2x2 left right

  -- Expected matrix product:
  --   19 22
  --   43 50
  let expected : TensorLib.Tensor.Format.Tree Float32 := TensorLib.Tensor.Format.Tree.node [
    TensorLib.Tensor.Format.Tree.root [19.0, 22.0],
    TensorLib.Tensor.Format.Tree.root [43.0, 50.0]
  ]

  -- Compare the actual numbers with the expected numbers.
  let actual := TensorLib.Tensor.toFloat32Tree! result.raw
  if actual != expected then
    throw (IO.userError "incorrect TensorLib matmul result")

  -- If we reach this line, the original matrix multiplication worked.
  IO.println "TENSORLIB_OK"
