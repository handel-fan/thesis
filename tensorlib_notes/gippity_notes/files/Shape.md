# `Shape.lean` — dimensions and coordinate arithmetic

A `Shape` wraps `List Nat` (nonnegative dimension sizes). It computes element count, rank, conventional row-major unit strides, and conversions between multidimensional indices and flat offsets. It also enumerates every valid coordinate, which is what tensor algorithms use for element-by-element traversal. The empty shape `[]` represents a **scalar**, whereas `[0]` represents a one-dimensional array with no elements.

```lean
structure Shape where
  val : List Nat
-- [2, 3] has unit strides [3, 1]
def dimIndexToOffset (strides : Strides) (index : DimIndex) : Offset :=
  dot strides (index.map Int.ofNat)
```

**Inspection method:** I followed `count`/`ndim` (92–95), `unitStrides` and its `#guard` examples (115–140), `dimIndexToOffset` (154), coordinate enumeration `allDimIndices` (160–169), and `belist` (186–199). The last one builds an iterator from the dimensions using `Iterator.BEList`, explaining why the last coordinate changes fastest in normal row-major traversals.
