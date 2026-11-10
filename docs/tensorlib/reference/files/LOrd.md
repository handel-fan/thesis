# `LOrd.lean` — proofs about floating-point order

`LOrd` introduces `POrd`, a typeclass describing a byte-encoded floating-point ordering, along with a decoder and proof obligations for reflexivity, antisymmetry, and transitivity when values are not NaN. It proves some underlying properties of Lean's `Float32` model, then provides `POrd` instances for float32, bfloat16, float16 and several float8 formats. Its special treatment of NaN and signed zero reflects the fact that ordinary IEEE comparisons are not a simple total order.

```lean
class POrd (dtype : Dtype) where
  decode : ByteArray → Float32
  le : ByteArray → ByteArray → Bool
  notNaN : ByteArray → Bool
  -- followed by three law/proof fields
```

**Inspection method:** I read the `POrd` obligations (37–47), model-level order proofs (59–360), and concrete instances (362–484). The `.float32` instance's `antisymm` proof ends with `sorry` at line 374, and analogous instances also use `sorry` (396, 418, 440, 462, 484). **This file contains unfinished proofs**; Lean's ability to accept `sorry` does not establish those properties from first principles.
