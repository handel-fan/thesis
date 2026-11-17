#!/usr/bin/env fish

# THIS FILE IS CALLED BY run.fish. DO NOT START HERE.
#
# PURPOSE: Perform the actual three Lean operations:
#   1. Compile LtomPocSupport.lean (the imported helper module).
#   2. Compile Main.lean to trigger our pass writing matmul.mlir.
#   3. Run Main.lean to check the original matrix multiplication.
#
# Lake has already prepared the Lean project's dependencies before
# run.fish launches this script.


# =============================================================
# PART 1: Receive the two folder paths from run.fish.
# =============================================================

# The first argument says where the POC source files live.
set -l poc_directory $argv[1]

# The second says where this run's messages/errors should go.
set -l log_directory $argv[2]

# Our new POC folder is not a standard Lake library directory.
# LEAN-SPECIFIC: LEAN_PATH lists places where Lean searches for
# imported compiled modules (.olean files).
#
# Lake already filled LEAN_PATH with the thesis project's dependencies.
# We add our POC folder in front without throwing away those paths.
set -gx LEAN_PATH "$poc_directory:$LEAN_PATH"


# =============================================================
# STEP 1: Compile the helper module.
# =============================================================

# WHY FIRST?
# Main.lean says `import LtomPocSupport`.
# Unlike a C++ textual #include, a Lean import normally loads information
# that was already compiled into a .olean file.
#
# `lean` starts the Lean compiler.
# `-o <output.olean> <source.lean>` asks it to produce compiled
# module information, NOT a standalone executable.

echo "[1/3] Compile the helper module"
if not lean -o "$poc_directory/LtomPocSupport.olean" \
    "$poc_directory/LtomPocSupport.lean" &> "$log_directory/support.log"

    echo "FAILED: compiling LtomPocSupport.lean"
    cat "$log_directory/support.log"
    exit 1
end


# =============================================================
# STEP 2: Compile Main.lean and trigger our StableHLO pass.
# =============================================================

# WHY COMPILE TO C?
# Our custom pass runs DURING Lean compilation, before C is generated.
# Asking Lean to generate C makes it execute the pass.
# We don't use the resulting C file; we want the .mlir file written
# DIRECTLY by the compiler pass.

set -l mlir_file "$poc_directory/artifacts/matmul.mlir"

# Remove the previous .mlir result so we can't accidentally mistake
# yesterday's file for an output from the current run.
# This does NOT remove any diagnostic logs.
if test -f "$mlir_file"
    rm "$mlir_file"; or exit 1
end

# `-c <output.c> <source.lean>` tells Lean to produce C code.
# Our custom pass writes `matmul.mlir` as a SIDE EFFECT of compiling.
echo "[2/3] Compile Main.lean; custom pass writes matmul.mlir"
if not lean -c "$poc_directory/artifacts/Main.c" \
    "$poc_directory/Main.lean" &> "$log_directory/compile.log"

    echo "FAILED: compiling Main.lean"
    cat "$log_directory/compile.log"
    exit 1
end

# Even successful compilation doesn't guarantee the custom pass ran.
# Check that it actually created a NONEMPTY StableHLO file.
if not test -s "$mlir_file"
    echo "FAILED: Lean compiled, but the pass did not write matmul.mlir"
    exit 1
end


# =============================================================
# STEP 3: Run the ORIGINAL Lean matrix multiplication.
# =============================================================

# This is an independent test of Main.lean.
# `--run` executes the Lean program DIRECTLY.
# We do NOT execute the C code or the generated StableHLO.
echo "[3/3] Run the real TensorLib matrix multiplication"
if not lean --run "$poc_directory/Main.lean" &> "$log_directory/runtime.log"

    echo "FAILED: running Main.lean"
    cat "$log_directory/runtime.log"
    exit 1
end

cat "$log_directory/runtime.log"
echo "SUCCESS: StableHLO was written directly to matmul.mlir"
