# Lean TensorLib -> StableHLO: direct-output POC

## Start here: what are we trying to do?

We wrote a Lean program that multiplies two 2x2 matrices. We want to see whether
**our own Lean compiler pass** can recognize the call and produce a StableHLO
(`.mlir`) file. StableHLO is a text-based representation of tensor operations.

A **compiler pass** is a function that the compiler runs while compiling a
program. It is not the matrix-multiplication function itself.

This POC does **two separate tests**:

### Test A — Does our compiler pass produce StableHLO?

```text
Main.lean (Lean program)
      |
      v
Lean compiler starts compiling Main.lean
      |
      v
Our custom pass notices the call to matmul2x2
      |
      v
Our pass writes artifacts/matmul.mlir directly
      |
      v
Lean continues compiling to Main.c (we do not use this file)
```

Important: **We deliberately ask Lean to compile to C to trigger the pass.**
The StableHLO comes from our pass, *not* from the C code.

### Test B — Does the original Lean program still run?

```text
Main.lean
    |
    v
Lean runs the program directly
    |
    v
Checks the matrix product against expected numbers
    |
    v
Prints TENSORLIB_OK if correct
```

We are **not** compiling or executing the StableHLO yet. A successful POC means
we generated a file and the original Lean computation worked; it does not yet
prove the StableHLO is accepted by an MLIR tool or numerically equivalent.

## Which file should I read first?

1. **`Main.lean`** — actual matrix multiplication. Start here.
2. **`LtomPocSupport.lean`** — our custom compiler pass. Follow the numbered
   sections. It is longer because Lean exposes lower-level compiler structures.
3. **`compile_in_project.fish`** — the three commands that compile and run Lean.
4. **`run.fish`** — starts everything and makes a fresh log directory.
5. **`copy_diagnostics.fish`** — collects logs and copies them to your clipboard.

You do **not** need to understand the entire compiler pass to understand the
project. It is useful to learn the goal first, then one section at a time.

## Lean-specific concepts you would not know from traditional C/C++

**`.olean`** — Lean's compiled information about a module. When `Main.lean`
imports `LtomPocSupport`, Lean reads `LtomPocSupport.olean`. This is **not**
a standalone executable or a C++ `.a` archive. That is why our runner compiles
the helper file first.

**LCNF** — one of Lean's internal representations of code during compilation.
Our pass examines this representation to find a function call. You do not
need to know its full structure to run this POC.

**`@[ltom_poc]`** — a tag we created for this experiment. It marks the
function call that our pass should look for. It is not a built-in Lean keyword.

**Lake** — the tool that manages the Lean project's dependencies. We use
`lake env fish other_script.fish` to start that other Fish script with the
project's Lean setup. Here `env` is one Lake subcommand; it is **not** the
Unix `env` command, and there is no `lake env env` in this project.

## Run the POC

From any folder, in Fish:

```fish
fish /Users/handelmac/handelmac_house/uml_handel/thesis/experiments/tlib_to_mlir_direct_poc/run.fish
```

You should see `[1/3]`, `[2/3]`, `[3/3]`, `TENSORLIB_OK`, then `SUCCESS`.

## Where are the results?

- `artifacts/matmul.mlir` — **the output we care about**. Our Lean pass writes it.
- `artifacts/Main.c` — created to trigger the pass; not used further.
- `artifacts/logs/<run-id>/support.log` — compiling the imported helper.
- `artifacts/logs/<run-id>/compile.log` — compiling Main and pass diagnostics.
- `artifacts/logs/<run-id>/runtime.log` — running the original matrix product.
- `artifacts/logs/<run-id>/lake.log` — overall runner output.

Each run gets a **new logs folder**; previous error logs are preserved. If
anything fails, the runner calls `copy_diagnostics.fish` automatically and
copies the combined report with `pbcopy` so you can paste it into ChatGPT.

To copy the newest run's logs manually:

```fish
fish /Users/handelmac/handelmac_house/uml_handel/thesis/experiments/tlib_to_mlir_direct_poc/copy_diagnostics.fish
```

## Current POC limitation

This pass handles one narrow example: a marked function with two tensor
arguments and a tensor result. It reads tensor shapes and types from that
function's declaration, then **builds a fixed `stablehlo.dot` template**.
It is not a general Lean-to-MLIR translator yet. Later extensions can add
more operations and proper validation of generated MLIR.
