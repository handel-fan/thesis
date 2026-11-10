# `Dtype.lean` — scalar types, bytes, and arithmetic

`Dtype` is an `inductive` type—roughly an enum—covering booleans, signed/unsigned integers, float8 variants, float16/bfloat16, float32 and float64. Beyond type names, it defines each element's byte size, numerical conversions, overflow/casting rules, dtype compatibility (`join`, `lossless`), and arithmetic on *one element's bytes*. In other words, `Ufunc` loops over tensors; `Dtype` says what `add` or `mul` means for each scalar byte sequence.

```lean
def itemsize (x : Dtype) : Nat := match x with
| float64 | int64 | uint64 => 8
| float32 | int32 | uint32 => 4
| bfloat16 | float16 | int16 | uint16 => 2
| bool | int8 | uint8 | float8_e4m3 | float8_e3m4 | float8_e5m2 | float8_e2m5 | float8_e8m0 => 1
```

**Inspection method:** I traced the type cases (30–49), promotion/lossless logic (159–359), float8 conversion paths (458–518), per-dtype arithmetic (`mul` at 866–906 and `div` at 908–947), `castOverflow` (1029 onward), and `roundToComputeDtype` (around 1170). The E8M0 type is explicitly **scale-only**: arithmetic and compute-rounding reject it. The file also contains extensive `#guard` checks; these are assertions in source, not tests I independently executed.
