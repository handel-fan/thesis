#!/usr/bin/env fish
# StableHLO numerical checks: MLIR contains check.expect_eq_const assertions.
if test (count $argv) -lt 1
    echo 'Usage: fish tests/check_results.fish <artifacts-directory>' >&2
    exit 2
end
set -l artifacts $argv[1]
if not command -q stablehlo-translate
    echo 'FAIL: stablehlo-translate not on PATH (no numerical MLIR tests executed)' >&2
    exit 4
end
for name in add2x2 add2x3 matmul2x3
    set -l mlir "$artifacts/$name.mlir"
    if not test -s "$mlir"
        echo "FAIL: missing generated MLIR: $mlir" >&2
        exit 5
    end
    if command -q stablehlo-opt
        stablehlo-opt "$mlir" >"$artifacts/$name.verified.mlir" 2>"$artifacts/$name.verify.log"
        or begin
            echo "FAIL: StableHLO verification: $name" >&2
            exit 6
        end
    end
    stablehlo-translate --interpret "$mlir" >"$artifacts/$name.interpret.log" 2>&1
    or begin
        echo "FAIL: StableHLO numerical check: $name" >&2
        exit 7
    end
    echo "STABLEHLO_OK $name"
end
