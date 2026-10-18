import TensorLib

open TensorLib


-- The usual 2D matmul
private def matmul2 (x y : Tensor) : Err Tensor := do
  let dtype := x.dtype
  if dtype != y.dtype then .error "Expected same dtype" else
  let (xd1, xd2, yd1, yd2) <- match x.shape.val, y.shape.val with
  | [xd1, xd2], [yd1, yd2] => .ok (xd1, xd2, yd1, yd2)
  | _, _ => .error "Expected 2d arrays"
  if xd2 != yd1 then .error "matmul2: reduction dimension mismatch" else
  let mut res := Tensor.zeros x.dtype (Shape.mk [xd1, yd2])
  for i in [0:xd1] do
    for j in [0:yd2] do
      let mut acc := dtype.zero
      for k in [0:xd2] do
        let u <- x.getDimIndex [i, k]
        let v <- y.getDimIndex [k, j]
        let m <- dtype.mul u v
        let acc' <- dtype.add acc m
        acc := acc'
      res <- res.setDimIndex [i, j] acc
  return res

def main : IO Unit := do
  IO.println "Starting l_to_mlir1.lean"
  let t1 := (Tensor.ofFloat32List! [1.0, 2.0, 3.0, 4.0]).reshape! (Shape.mk [2, 2])
  let t2 := (Tensor.ofFloat32List! [5.0, 6.0, 7.0, 8.0]).reshape! (Shape.mk [2, 2])

  let t3 <- match matmul2 t1 t2 with
    | .ok result => pure result
    | .error msg => throw (IO.userError msg)

  let values <- match t3.toList with
    | .ok xs => pure xs
    | .error msg => throw (IO.userError msg)

  for bytes in values do
    match Float32.ofLEByteArray bytes with
    | .ok value => IO.println (repr value)
    | .error msg => throw (IO.userError msg)
