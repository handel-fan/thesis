# `Slice.lean` — normalizing slice syntax

This file models Python/NumPy's `start:stop:step` syntax, including omitted bounds, negative indices, and reverse traversal. A `Slice` carries optional signed integers and a Lean proof that `step` is not zero; `Slice.make` refuses zero steps. The file then resolves defaults against a concrete dimension length, calculates the number of selected positions, and constructs `Slice.Iter` to enumerate actual indices.

```lean
structure Slice where
  start : Option Int
  stop : Option Int
  step : Option Int
  stepNz : step ≠ .some 0
```

**Inspection method:** I traced `startOrDefault` (170–182), `stopOrDefault` (194–207), `size` (272–280), and the iterator `make`/`next` implementation (522–548). The `theorem` declarations around stop and step establish invariants Lean needs for these cases; the numerous `#guard` examples around lines 282–400 and 560–563 check forward/reverse sequences. `Slice.Iter.make` returns an error for an empty slice iterator (530–536), which is worth noting when reviewing edge cases.
