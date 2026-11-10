# `Float.lean` — exact floating-point bit formats

This is the low-level floating-point encoding layer. It adds conversions between Lean's `Float32`/`Float` and packed float16, bfloat16, and several float8 formats; it explicitly manipulates sign, exponent, and mantissa bits, including NaNs, infinities, subnormals, overflow, and rounding. The file does **not** define tensor operations; it provides the scalar bit conversions that `Dtype.lean` uses.

```lean
def _root_.Float32.toFloat16Bits (f : Float32) : UInt16 :=
  let bits := f.toBits
  let sign := (bits >>> 31) &&& 1
  let exp := (bits >>> 23) &&& 0xFF
```

**Inspection method:** I read float16 encoding/decoding (154–267), E4M3 encoding/decoding (278–401), other float8 paths (402–797), and the E8M0 scale decoder (666–678). The guards at 680–686 explicitly check `127 → 1.0`, `128 → 2.0`, `0 → 2⁻¹²⁷`, and `255 → NaN`. The internal comments distinguish formats with and without infinity and document known NaN-sign limitations.
