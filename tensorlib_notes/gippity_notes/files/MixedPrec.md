# `MixedPrec.lean` — error bounds for reduced precision

This is formal numerical-analysis work rather than a tensor executor. It defines mantissa widths and `machineEpsilon`, then states Lean theorems bounding the error when a `Float32` value is rounded to a float8 format and when two approximated operands are added. The bounds are conditional on representable range and other assumptions. Its main targets are `pointwiseBoundE4M3`, generic `pointwiseBound`, and `additionErrorBound`.

```lean
def machineEpsilon (dtype : Dtype) : Option Float32 :=
  (mantissaBits dtype).map (fun k => Float32.pow 2.0 (-k.toFloat32))
-- A central result:
theorem additionErrorBound (dtype : Dtype) ...
```

**Inspection method:** I traced precision data (33–46), the E4M3 error proof (285–316), generic bound (555–560), and addition bound (601–620). Crucial qualification from the actual source: there are **16 declared `axiom`s** (including floating-point algebra and normal-range rounding assumptions). The theorems therefore depend on assumptions not discharged here; they are **not** a fully closed IEEE-754 verification.
