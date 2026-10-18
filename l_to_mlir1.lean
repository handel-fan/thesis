def main : IO Unit := do
  IO.println "Starting l_to_mlir1.lean"
  let t1 := (Tensor.ofFloat32List! [1.0, 2.0, 3.0, 4.0]).reshape! (Shape.mk [2, 2])
  let t2 := (Tensor.ofFloat32List! [5.0, 6.0, 7.0, 8.0]).reshape! (Shape.mk [2, 2])

  let values <- match t3.toList with
    | .ok xs => pure xs
    | .error msg => throw (IO.userError msg)

  for bytes in values do
    match Float32.ofLEByteArray bytes with
    | .ok value => IO.println (repr value)
    | .error msg => throw (IO.userError msg)
