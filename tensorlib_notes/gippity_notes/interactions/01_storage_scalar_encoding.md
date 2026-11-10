# Interaction 1 — `Tensor` ⇄ `Dtype` ⇄ `Float`/`Bytes`

**Path:** `Tensor.lean` stores the bytes; `Dtype.lean` decides what those bytes mean; `Float.lean`, `Bytes.lean`, and `ByteArray.lean` perform low-level encoding/decoding. There is no separate generic element array inside `Tensor`.

```lean
-- Tensor.lean
let v <- arr.getDimIndex dimIndex
let v' <- Dtype.castOverflow arr.dtype v toDtype
let res' <- res.setDimIndex dimIndex v'
```

`astype` (Tensor lines 466–478) is a concrete example: it iterates coordinates, decodes/casts one element via `Dtype`, then writes its encoded bytes. `Dtype.mul` similarly decodes bytes, computes in the appropriate scalar representation, and encodes again (Dtype lines 866–906). **Review method:** traced each call across these files and checked the relevant float encoding routines, including E8M0's special decoder in `Float.lean` (666–678). For a compiler lowering, dtype-specific scalar semantics are concentrated here, not in the `Tensor` record.
