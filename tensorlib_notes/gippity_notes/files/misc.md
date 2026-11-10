# Supporting files (`misc.md`)

These six files matter, but they are not the first place to look to understand tensors, operations, or the numerical proofs. Each summary below comes from the uploaded source itself.

## `Basic.lean` — import hub

This is simply the aggregation point for TensorLib modules, not an implementation: `import TensorLib.Tensor`, `import TensorLib.Ufunc`, `import TensorLib.MixedPrec`, etc. Import it if you want the library's major pieces brought into the Lean environment.

**Inspected:** I read its complete short import list (lines 17–33); there are no tensor definitions or algorithms in this file.

## `Common.lean` — shared types and errors

Defines `Err := Except String` (a result that is success or an error message), `get!` (panics on error), dimension/offset aliases, and helpers such as `natProd` and `dot`. Almost every core module relies on its basic vocabulary.

**Inspected:** I checked `Err` and its `MonadLift` instances (23–33), `get!` (37–39), `dot` (49), and `Strides`, `DimIndex`, `Position`, `Offset` (97–117). Example: `abbrev DimIndex := List Nat`.

## `Bytes.lean` — number → byte-array conversions

Declares `ToLEByteArray` and `ToBEByteArray`, the typeclasses used to serialize primitive values with little- or big-endian byte order. It implements them for booleans and fixed-width signed/unsigned integers.

**Inspected:** I read the classes (20–28) and several integer instances: `UInt16` little-endian creates `#[b0, b1]` (61–65), while big-endian creates `#[b1, b0]` (67–71). `Dtype` and `Tensor` reuse these conversions.

## `ByteArray.lean` — byte-buffer helpers

Extends Lean's byte arrays with checked fixed-width reads, signed/unsigned conversions, slicing, zero-filled buffers, and BitVec encoding/decoding. It is the bridge between raw bytes and typed scalar values.

**Inspected:** I followed the checked `toUInt64LE` (38–39), `toNat`/`toInt` (94–125), `zeros` plus its size theorem (188–194), and `BitVec` conversions (196–226). For example, `ByteArray.zeros n := ByteArray.replicate n 0`.

## `Mgrid.lean` — coordinate grids

Implements a restricted version of NumPy's `mgrid`: given explicit `start:stop:step` slices, it creates an `int64` tensor containing coordinate grids, with an extra leading axis identifying which coordinate each value represents.

**Inspected:** I checked its `Slice` → `IntIter` conversion (84–88) and `mgrid` body (163–179). It combines coordinate-product iterators with `Tensor.setDimIndex`; unlike usual slicing, it rejects missing start/stop limits.

## `Test.lean` — integration/edge-case tests

Contains `IO` tests for packed numerical formats, quantization/dequantization, and rounding, with helper code for NumPy comparison. It does not define the tensor abstraction itself.

**Inspected:** I reviewed the test entry points (50–58, 281–398, 807–937) and `runAllTests` (939–951), which chains the float16, bfloat16, float8, MX, and compute-rounding checks. I inspected test source but did not execute it.
