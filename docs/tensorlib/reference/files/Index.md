# `Index.lean` — NumPy-style indexing and assignment

Basic indices are represented by the `NumpyItem` enum: integer, slice, ellipsis, or new axis. `toBasicIter` translates those items into concrete slice iterators and computes the result shape. `Index.apply` gathers chosen elements into a **fresh contiguous byte array** (not a zero-copy view), while `Index.assign` writes values back into a new tensor, broadcasting the assigned value to the selected shape. `Advanced.apply` supports arrays of integer indices for all input dimensions, but not mixtures of basic and advanced indexing.

```lean
inductive NumpyItem where
| int (n : Int)
| slice (slice : Slice)
| ellipsis
| newaxis
```

**Inspection method:** I followed `toBasicIter` (80–116), its coordinate loop in `apply` (137–153), `assign` (178–188), and the advanced gather (230–253). A code-level caveat: advanced indexing computes a broadcasted output shape but calls `indexTensor.reshape outShape` (239), **not** `broadcastTo`; that need not work for shapes whose element counts differ. The source's assertion that this reshape “should never fail” is not generally justified by broadcasting rules.
