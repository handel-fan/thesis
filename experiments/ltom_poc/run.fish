#!/usr/bin/env fish

# PURPOSE:
# Test whether our custom Lean compiler pass produces StableHLO
# for a matrix multiplication program.
#
# Run this script from the project's root directory.
#
# The project contains:
#   Main.lean             - The matrix multiplication program
#   LtomPocSupport.lean   - Code imported by Main.lean
#   lakefile.toml         - Configuration for our Lean project
#
# We will save generated files and compiler messages in artifacts/.

# -------------------------------------------------------
# SETUP: Create a folder to store our results.
# -------------------------------------------------------

set -l output_directory artifacts

# Create the directory if it doesn't exist.
mkdir -p "$output_directory"; or exit 1

# -------------------------------------------------------
# STEP 1: Compile the helper code.
# -------------------------------------------------------

# Lean-specific detail:
#
# Main.lean imports LtomPocSupport.
# Lean expects the imported module to have been compiled
# into a .olean file before Main.lean can use it.
#
# Lake is Lean's build tool.
# We ask Lake to build LtomPocSupport, which we have
# registered as a library in lakefile.toml.
#
# Lake handles finding dependencies and storing the
# compiled .olean file in the project's build directory.

echo "STEP 1/4: Compile the support module"

# &> saves normal messages AND errors to support.log.
#
# "if not" means:
# If the compilation fails, print the errors and stop.

if not lake build LtomPocSupport &>"$output_directory/support.log"
    cat "$output_directory/support.log"
    exit 1
end

# -------------------------------------------------------
# STEP 2: Compile Main.lean, triggering our custom pass.
# -------------------------------------------------------

# We want the StableHLO produced by our compiler pass.
#
# Our pass runs DURING compilation, before C is generated.
# To trigger it, we ask Lean to compile Main.lean into C.
#
# We don't actually need the resulting C file.
#
# "lake env lean" means:
# Run the Lean compiler with this project's dependencies
# available. Lake takes care of that setup.
#
# -c tells Lean to generate a C file.

echo "STEP 2/4: Compile Main.lean and trigger StableHLO generation"

if not lake env lean \
        -c "$output_directory/Main.c" \
        Main.lean &>"$output_directory/compile.log"

    cat "$output_directory/compile.log"
    exit 1
end

# -------------------------------------------------------
# STEP 3: Extract StableHLO from the compiler's messages.
# -------------------------------------------------------

# Our custom compiler pass prints StableHLO into the
# compiler's output, marked with [SHLO].
#
# We captured that output in compile.log during step 2.
#
# The Python script reads compile.log, finds the StableHLO,
# and writes it into a separate .mlir file.
#
# .mlir is a text format used to represent MLIR code.
#
# We use a separate Python file rather than embedding
# a Python program inside this Fish script.

echo "STEP 3/4: Extract StableHLO"

if not python3 scripts/extract_stablehlo.py \
        "$output_directory/compile.log" \
        "$output_directory/matmul.mlir"

    exit 1
end

# -------------------------------------------------------
# STEP 4: Run the actual matrix multiplication program.
# -------------------------------------------------------

# We have tested whether the compiler produces StableHLO.
#
# Now we separately run Main.lean to test whether the
# original matrix multiplication program still works.
#
# --run tells Lean to execute Main.lean directly.
#
# This does NOT run the C file generated in step 2.

echo "STEP 4/4: Execute matrix multiplication"

if not lake env lean --run Main.lean &>"$output_directory/runtime.log"
    cat "$output_directory/runtime.log"
    exit 1
end

# Show the output produced by the running program.
cat "$output_directory/runtime.log"

echo "POC COMPLETE"
echo "StableHLO saved to $output_directory/matmul.mlir"
