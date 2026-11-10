# Interaction 2 — `Shape` → `Broadcast` → `Tensor` → `Ufunc`

**Path:** A binary operation can accept different shapes because `Broadcast.broadcast` first computes a common shape. `Tensor.broadcastTo` then represents the expanded dimensions with **stride zero**, so the same source element can be read repeatedly without expanding its data. `Ufunc.binop` iterates that common shape and computes the resulting elements.

```lean
-- Tensor.lean, broadcastStrides
else if xDim == 1 then do
  let rest <- loop xs ys
  return 0 :: rest
-- Ufunc.lean, binop
let (x, y) <- x.broadcast y
```

**Review method:** compared shape pairing (`Broadcast.lean` 68–106), tensor stride construction (`Tensor.lean` 258–308), and the actual element loop (`Ufunc.lean` 72–84). This is a **view for the broadcast operands but a newly computed result tensor**. It is one of the most important dataflow paths for understanding how an elementwise computation could be lowered.
