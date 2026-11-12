# LTOM typed lowering — Lean 4.33 POC

## Purpose

Experiment with a Lean compiler extension **without editing Lean or TensorLib**.
The compiler pass runs after the first LCNF initialization pass and recognizes
**only calls annotated `@[ltom_handel]`**. It looks up each declaration's original
signature with `getConstInfo`, matches each surviving LCNF argument to the
corresponding parameter, reads concrete tensor shapes and dtype (`f32`), and
prints test StableHLO modules. It deliberately does **not** inspect operation
implementations.

The test uses real TensorLib tensors with proof-carrying typed wrappers.
`TypedTensor.check` checks that runtime shape/dtype match the encoded type.
Because the wrappers carry proofs, construction of a valid value cannot simply
assert an unchecked shape.

## Run

From anywhere after unzipping the folder into the thesis repository:

```fish
fish experiments/ltom_typed_lowering/run.fish
```

The runner uses only Fish and external Lean/StableHLO command-line utilities.
It requires Lean 4.33 + TensorLib from your project's Lake setup, and
`stablehlo-translate` on `PATH`. `stablehlo-opt` is used if available.
All generated results live under `artifacts/`.

## Success conditions

- All three annotated calls appear in early LCNF: `ltomAdd2x2`, `ltomAdd2x3`, `ltomMatmul2x3`.
- For every call, each surviving operand has a matching parameter with a concrete
  `tensor<...xf32>` type (otherwise the run fails).
- Lean rejects `tests/InvalidShapes.lean` with a type mismatch.
- The real TensorLib implementations return expected values for three cases.
- The emitted StableHLO modules verify when `stablehlo-opt` is available and
  execute under `stablehlo-translate --interpret`. Each contains a
  `check.expect_eq_const` assertion for the expected numerical result.

## Scope and boundaries

This is a **call-contract and standalone operation lowering POC**; it is not yet
whole-program compilation of arbitrary Lean control flow or a TensorLib runtime
replacement. MLIR input tensors are fixed test fixtures. The generated
StableHLO code takes its *types* from the annotated function signatures, but
the operation selection and fixtures are explicitly registered in
`LtomSupport.lean` and `EmitStableHLO.lean` respectively.

The pass checks positional parameter correspondence at its interception point.
It does not yet prove that all possible initial-LCNF transformations preserve
annotations or operand correspondence, and it does not handle polymorphic
dimension instantiation. These are separate future experiments rather than
claims of POC success.

## Files

- `LtomTypedLowering/TypedTensor.lean`: tensor wrapper and checked constructor.
- `LtomTypedLowering/EmitStableHLO.lean`: reads concrete tensor types from
  elaborated declaration signatures, maps them to MLIR types, emits test modules.
- `LtomTypedLowering/LtomSupport.lean`: registers `@[ltom_handel]` and the early
  LCNF inspection pass; collects typed operand information.
- `examples/Add.lean` and `examples/Matmul.lean`: annotated real TensorLib calls
  and numerical checks.
- `tests/InvalidShapes.lean`: deliberately ill-typed Lean source.
- `tests/check_results.fish`: interpreter-based StableHLO numerical checks.
- `run.fish`: repeatable setup, build, run, diagnostics and summaries.
- `artifacts/`: generated `.olean`, `.c`, `.mlir`, compiler and execution logs.

## Troubleshooting output

If the command fails, upload `artifacts/*.build.log`, `artifacts/*.compile.log`,
`artifacts/ltom_compiler.log`, and `artifacts/stablehlo_tests.log` when present.
The runner intentionally stops on failures rather than claiming success.

**Environment limitation:** These files were authored without a Lean 4.33 or
StableHLO executable in the authoring environment. They need a build/run against
your Mac toolchain before their success can be claimed.
