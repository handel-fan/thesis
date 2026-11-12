#!/usr/bin/env fish
# Run from ANY directory. Only writes under experiments/ltom_typed_lowering/artifacts.
set -l here (dirname (status --current-filename))
set -l root (realpath "$here/../..")
set -l project (realpath "$here")
set -l art "$project/artifacts"
set -l oleans "$art/oleans"
mkdir -p "$oleans/LtomTypedLowering/Examples"
cd "$root"; or exit 2
if not command -q lake
    echo 'ERROR: lake not available' >&2
    exit 2
end
set -gx LTOM_OLEANS "$oleans"
set -gx LTOM_LAKE_PATH (lake env printenv LEAN_PATH)
function ltom_lean
    lake env env LEAN_PATH="$LTOM_OLEANS:$LTOM_LAKE_PATH" lean $argv
end
function failure
    echo "FAIL $argv[1] — see artifacts/*.log" >&2
    exit 1
end
set -l src "experiments/ltom_typed_lowering"
lake env lean --version >"$art/lean_version.txt" 2>&1
set -l modules TypedTensor EmitStableHLO LtomSupport
for module in $modules
    echo "[compile] $module"
    ltom_lean -o "$oleans/LtomTypedLowering/$module.olean" "$src/LtomTypedLowering/$module.lean" >"$art/$module.build.log" 2>&1
    or failure "$module support build"
end
for example in Add Matmul
    echo "[compile] $example"
    ltom_lean -o "$oleans/LtomTypedLowering/Examples/$example.olean" "$src/examples/$example.lean" >"$art/$example.olean.log" 2>&1
    or failure "$example olean build"
    ltom_lean -c "$art/$example.generated.c" "$src/examples/$example.lean" >"$art/$example.compile.log" 2>&1
    or failure "$example C/LCNF build"
    echo "[execute TensorLib] $example"
    ltom_lean --run "$src/examples/$example.lean" >"$art/$example.run.log" 2>&1
    or failure "$example TensorLib run"
end
# Prove that invalid shapes are rejected by the Lean type checker.
ltom_lean "$src/tests/InvalidShapes.lean" >"$art/InvalidShapes.log" 2>&1
if test $status -eq 0
    failure 'InvalidShapes unexpectedly type-checked'
end
rg -q 'type mismatch|application type mismatch|has type|expected' "$art/InvalidShapes.log"
or failure 'InvalidShapes failed for an unexpected reason'
echo 'LEAN_TYPECHECK_OK InvalidShapes rejected'

# Gather annotated-call messages and emitted text. Fish reconstructs real MLIR
# source lines from the @@NL@@ markers printed by our Lean compiler pass.
cat "$art/Add.compile.log" "$art/Matmul.compile.log" >"$art/ltom_compiler.log"
rg '\[LTOM\]|\[LTOM_PARAM\]|\[LTOM_RESULT\]|\[LTOM_ERROR\]' "$art/ltom_compiler.log" > "$art/ltom_summary.txt"
if rg -q '\[LTOM_ERROR\]|error:' "$art/ltom_compiler.log"
    failure 'LCNF pass contract extraction'
end
for line in (rg '\[LTOM_MLIR\] ' "$art/ltom_compiler.log")
    set -l stripped (string replace -r '^.*\[LTOM_MLIR\] ' '' -- "$line")
    set -l parts (string split -m1 '|' -- "$stripped")
    if test (count $parts) -ne 2
        failure 'MLIR log extraction'
    end
    set -l name $parts[1]
    set -l file "$art/$name.mlir"
    printf '%s\n' (string split '@@NL@@' -- "$parts[2]") >"$file"
    echo "GENERATED $file"
end
for name in add2x2 add2x3 matmul2x3
    test -s "$art/$name.mlir"; or failure "missing $name.mlir"
    rg -q "TENSORLIB_OK $name" "$art/"*.run.log; or failure "TensorLib value check $name"
    echo "LEAN_LCNF_OK $name"
end
fish "$project/tests/check_results.fish" "$art" >"$art/stablehlo_tests.log" 2>&1
or begin
    cat "$art/stablehlo_tests.log"
    failure 'StableHLO execution'
end
cat "$art/stablehlo_tests.log"
echo 'PASS: annotated LCNF calls, concrete tensor types, Lean shape rejection, TensorLib outputs, StableHLO interpreter outputs'
