#!/usr/bin/env fish
begin
    echo "== Lean toolchain =="
    lake env lean --version
    echo "== Compiling probe =="
    lake env lean -o Probe.olean Probe.lean
    or exit $status
    echo "== Generating C and running LCNF probes =="
    lake env lean -c Main.c Main.lean
    or exit $status
    echo "== Running program =="
    lake env lean --run Main.lean
end 2>&1 | tee /dev/tty | pbcopy
