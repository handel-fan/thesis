# `Iterator.lean` — reusable tensor-coordinate loops

`Iterator` is a Lean **typeclass** (an interface resolved by the type system) giving an iterator `peek`, `next`, `reset`, and `size`. An instance also makes the iterator usable in ordinary `for ... in ...` loops. The file implements natural-number and signed integer ranges, lockstep pairs, and Cartesian products of iterators. `BEList` changes the rightmost coordinate fastest, the ordering tensor traversal requires.

```lean
class Iterator (iter value : Type) where
  next : iter -> Option iter
  peek : iter -> value
  size : iter -> Nat
  reset : iter -> iter
```

**Inspection method:** I read its `ForIn` adapter (39–52), `NatIter` (60–76), `IntIter` (106–145), the pair-lockstep instances (163–238), and list-product `LEList`/`BEList` (254–315). The guard at 322–331 enumerates `[0,0], [0,1], ...` for a `BEList` of two ranges; `Shape.belist` builds exactly this kind of iterator.
