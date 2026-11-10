# `Npy.lean` — NumPy `.npy` file format

`Npy` describes an on-disk array as a header (`dtype`, byte order, shape, version), raw data, and an offset at which the data starts. It parses `.npy` magic bytes and its three metadata fields, and can serialize an array back to disk. This is file-format I/O, not tensor arithmetic; `Tensor.ofNpy` and `Tensor.toNpy` convert between the file representation and the core tensor representation.

```lean
structure Ndarray where
  header : Header
  data : ByteArray
  startIndex : Nat
```

**Inspection method:** I followed dtype-string conversion (88–141), header parsing (`parseHeader` 300–316 and metadata 320–359), `parseFile` (366–368), and save functions (396–434). Specific boundaries found: Fortran-order files are rejected (354–356); the one-byte `V1` descriptor cannot distinguish several float8 variants (114–138). `Tensor.toNpy` refuses some ambiguous float8 saves rather than allowing silent reinterpretation.
