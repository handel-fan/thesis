# TensorLib source-reading notes

These notes are based **only on the 18 uploaded `.lean` files**. I inspected their contents, traced calls across modules, checked nearby examples, `#guard` assertions, proof declarations, and explicit limitations. I did **not** fetch external code, run Lean, compile the project, or execute tests; all claims about behavior are **static source inspection**, with code excerpts/line locations to make that checkable. Line numbers refer to the provided copies.

If you know functional programming but not Lean: `structure` ≈ record, `inductive` ≈ algebraic datatype, `class`/`instance` ≈ typeclass/interface and implementation, `Option` ≈ maybe, `Err a` ≈ `Except String a`, `do`/`let x <- ...` sequences effectful/error-returning calls, `theorem` introduces a proposition to prove, `by` starts proof tactics, `#guard` checks a proposition/Boolean during elaboration, and `sorry` admits a proof without completing it. A name ending in `!` generally denotes an unchecked/panic-on-error wrapper **in this codebase**, not mutation.

## Core files (12)

- [Tensor.lean](files/Tensor.md) — the actual tensor storage/view model; **start here**.
- [Dtype.lean](files/Dtype.md) — scalar formats, casts, arithmetic.
- [Shape.lean](files/Shape.md) — dimensions, strides, coordinates.
- [Broadcast.lean](files/Broadcast.md) — compatible shapes.
- [Ufunc.lean](files/Ufunc.md) — elementwise operations, reductions, matmul.
- [Index.lean](files/Index.md) — slicing/indexing and assignment.
- [Slice.lean](files/Slice.md) — `start:stop:step` semantics.
- [Iterator.lean](files/Iterator.md) — iteration engine.
- [Float.lean](files/Float.md) — packed floating-point bit conversions.
- [Npy.lean](files/Npy.md) — NumPy file input/output.
- [MixedPrec.lean](files/MixedPrec.md) — conditional reduced-precision error bounds.
- [LOrd.lean](files/LOrd.md) — floating-point order proof framework.

[**misc.md**](files/misc.md) covers the six smaller/less-central files: `Basic`, `Common`, `Bytes`, `ByteArray`, `Mgrid`, and `Test`.

## Key cross-file interactions (7)

1. [Storage and scalar encoding](interactions/01_storage_scalar_encoding.md)
2. [Broadcasting into elementwise operations](interactions/02_broadcast_to_elementwise.md)
3. [Slices, indices, iteration, and copying](interactions/03_slices_indices_and_iteration.md)
4. [Batched matrix multiplication call chain](interactions/04_matmul_dataflow.md)
5. [NumPy file round-trip](interactions/05_numpy_roundtrip.md)
6. [Mixed-precision computations and proof chain](interactions/06_mixed_precision_proof_chain.md)
7. [The shared iteration mechanism](interactions/07_iteration_shared_mechanism.md)

**Most useful reading order for understanding computational semantics:** `Tensor` → `Shape` → `Dtype` → `Broadcast` → `Ufunc` → `Index`. For verification issues, next read `Float` → `LOrd` → `MixedPrec`.

**Important limitations found in source:** `Tensor.transpose` currently recomputes default strides rather than permuting existing strides; `Index.apply` copies rather than returning a view; `Index.Advanced.apply` uses `reshape` where broadcasting may be needed; `MixedPrec` declares 16 axioms, and `LOrd` contains `sorry` proofs. These are code-review findings, not executed defect demonstrations.
