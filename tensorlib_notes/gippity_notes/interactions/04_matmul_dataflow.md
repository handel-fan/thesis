# Interaction 4 — batched matrix multiplication calls across modules

**Path:** `Ufunc.matmul` uses `Broadcast` only for *leading batch dimensions*, preserving the final matrix dimensions for multiplication. It broadcasts the input tensors to the batch shape, reshapes them into `[batchCount, rows, cols]`, selects each batch with `Index.apply`, calls the scalar-loop `matmul2`, writes the result back with `Index.assign`, and restores the final shape.

```lean
-- Ufunc.lean
let x' <- Index.apply index x
let y' <- Index.apply index y
let v <- matmul2 x' y'
res <- Index.assign res index v
```

**Review method:** traced `matmul2` (Ufunc 185–203) and the complete batched path (217–254), checking the broadcast and index implementations it invokes. The current computation is an explicit nested-loop implementation (`i`, `j`, `k`), **not** a call to BLAS or GPU code. This call chain is a useful concrete target for a future MLIR `matmul`-style lowering.
