# `Ufunc.lean` — tensor operations

This is the public computational layer for NumPy-like tensor operations. `unop` and `binop` walk tensor coordinates and apply `Dtype`'s byte-level operators to each element, giving addition, subtraction, multiplication, division, and unary functions. It also implements reductions (`sum`), 1-D `dot`, 2-D matrix multiplication, batched `matmul`, logical/bitwise functions, and `full`/`ones`. These are eager elementwise loops, not an IR or a lazy graph.

```lean
def add (x y : Tensor) : Err Tensor := binop x y x.dtype.add
-- Inside binop:
let (x, y) <- x.broadcast y
for idx in shape.belist do
  let v <- x.getDimIndex idx
```

**Inspection method:** I traced `binop` (72–84), including its explicit rejection of implicit mixed-dtype arithmetic; `sum` (105–157); `dot`/`matmul` (167–254); and the float/logical wrapper functions (258–319). `matmul` notably calls `Broadcast`, `Tensor.reshape`, `Index.apply`, and `Index.assign`. The NKI kernel sketch near 478–509 is **inside a block comment** with `sorry` placeholders, not an implemented compiled kernel.
