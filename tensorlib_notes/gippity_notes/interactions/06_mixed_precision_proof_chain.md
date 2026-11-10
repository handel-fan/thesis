# Interaction 6 — scalar conversions → error analysis → proof obligations

**Path:** `Float.lean` implements rounding into packed floating-point formats. `Dtype.roundToComputeDtype` exposes that as a Float32 → lower-precision → Float32 operation. `MixedPrec.lean` states and proves **conditional** numerical error bounds about that function, while `LOrd.lean` supplies Float32 ordering lemmas and `POrd` instances. `Tensor.quantizeMX`/`dequantizeMX` uses some of the same low-level formats for actual block-scaled array calculations.

```lean
-- Dtype.lean
| .float8_e4m3 => decodeFloat8E4M3 (ByteArray.mk #[v.toFloat8E4M3Bits])
-- MixedPrec.lean
axiom float32_eq_add_sub (v x : Float32) : v = x + (v - x)
```

**Review method:** traced E4M3 bit conversion (`Float.lean` 278–401), compute rounding (`Dtype.lean`, `roundToComputeDtype`), bounds (`MixedPrec.lean` 285–316 and 555–620), `POrd` proofs (`LOrd.lean` 37–47, 362–484), and MX tensor functions (`Tensor.lean` 702–865). **Do not present these as complete proofs of numerical correctness:** `MixedPrec` has 16 axioms, and `LOrd` has admitted `sorry` cases. The unconditional nature of some Float32 algebra axioms is itself a separate soundness concern for real IEEE floating-point arithmetic.
