# Interaction 7 — the shared iteration mechanism

**Path:** Many otherwise different features all use the same iteration machinery. `Shape.belist` builds a rightmost-fastest Cartesian iterator over dimensions; `Tensor.copy`, `Tensor.astype`, and `Ufunc.binop` loop over those coordinates. Meanwhile `Index` creates Cartesian products of `Slice.Iter`s, and `Mgrid` pairs a grid of coordinate values with the corresponding tensor indices.

```lean
-- Shape.lean
def belist (shape : Shape) : Iterator.BEList Iterator.NatIter :=
  Iterator.BEList.make $ shape.val.map Iterator.NatIter.make
-- Tensor.lean
for dimIndex in arr.shape.belist do
```

**Review method:** checked `Iterator.forInInstance` (39–52), `BEList.make` and its `next` (309–315), `Shape.belist` (186–187), `Index.belist` (118), and `Mgrid.mgrid` (163–179). The ordering is not incidental: these loops prescribe how the library physically visits tensor elements, including views with nonstandard strides.
