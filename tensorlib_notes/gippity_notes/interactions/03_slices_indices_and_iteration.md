# Interaction 3 — `Slice` + `Iterator` + `Index` + `Tensor`

**Path:** The `Slice` representation turns `start:stop:step` into a concrete sequence (`Slice.Iter`). `Index.toBasicIter` assembles one such sequence per axis, and `Iterator.BEList` visits the Cartesian product of their positions. `Index.apply` reads each chosen value from `Tensor` and appends the bytes to a **new** buffer; `Index.assign` instead writes matching values into a copied/updated tensor.

```lean
-- Index.lean, apply
for dimIndex in iter do
  let posn := arr.dimIndexToPosition dimIndex
  for j in [0:itemsize] do
    data := data.push (arr.data.get! (posn + j))
```

**Review method:** traced `Slice.Iter.make`/`next` (522–548), `Iterator.BEList` (309–315), `Index.toBasicIter`/`apply` (80–153), and `Tensor.dimIndexToPosition` (121–127). Important limitation: basic slicing is currently a **gather/copy**, not NumPy's usual shared-storage view. Advanced indexing uses integer tensors but does not implement mixing basic and advanced forms; its `reshape` vs `broadcastTo` choice also deserves attention (Index line 239).
