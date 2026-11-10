# `Tensor.lean` — core tensor representation

A `Tensor` is an actual multidimensional array: its elements live in a `ByteArray`, while `dtype`, `shape`, `startIndex`, and `unitStrides` tell the code how to interpret those bytes. `unitStrides` measure jumps in *elements*, not bytes. The file supplies creation (`zeros`, `arange`), reads/writes, contiguous copies, reshaping, broadcasting views, casting (`astype`), NumPy I/O, and block-scaled `quantizeMX`/`dequantizeMX`. Updates build a new tensor/byte array rather than mutating shared storage.

```lean
structure Tensor where
  dtype : Dtype
  shape : Shape
  data : ByteArray
  startIndex : Nat := 0
  unitStrides : Strides := shape.unitStrides
```

**Inspection method:** I read the representation and its rationale (lines 27–90), followed index-to-byte addressing (121–145), `copy`/`reshape` (163–241), zero-stride `broadcastTo` (258–308), `astype` (466–478), and MX quantization (702–865). A noteworthy implementation detail: `transpose` (250–256) reverses the shape but recomputes default strides; it does **not** swap existing strides, so it should not be assumed to implement a normal NumPy transpose correctly. This is a source-reading conclusion, not a runtime test.
