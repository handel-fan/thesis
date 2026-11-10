# Interaction 5 — `Npy` ⇄ `Tensor` ⇄ `Dtype`

**Path:** `Npy.lean` parses/serializes a disk file with dtype and shape metadata; `Tensor.ofNpy` takes the bytes after the header and converts endianness to the library's expected layout. `Tensor.toNpy` ensures the tensor is contiguous first, then emits its dtype, shape, and data via `Npy.Ndarray`.

```lean
-- Tensor.lean
let data <- dataOfNpy arr
return { dtype, shape, data, startIndex }
-- Export forces contiguous data when needed:
let arr := if arr.isTriviallyReshapable then arr else arr.copy
```

**Review method:** followed the `.npy` parser and dtype-string mapping (`Npy.lean` 88–141, 300–368), then the two adapter functions (`Tensor.lean` 653–698). Relevant limitations: Fortran order is rejected; native-endian input requires explicit handling; and some float8 types share ambiguous `.npy` descriptors, so `Tensor.toNpy` rejects unsafe cases.
