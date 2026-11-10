#!/usr/bin/env fish
# Run from the root of the Lake project.
set -l support LtomProbeSupport.lean
set -l source examples/l_to_mlir/ltom_probe.lean
set -l log ltom_probe.log
set -l summary ltom_probe_summary.txt
set -l version_file ltom_lean_version.txt
set -l generated_c ltom_probe_generated.c

if not test -f $support; or not test -f $source
    echo "Missing $support or $source; run from your project root." >&2
    exit 2
end

# Lake supplies dependency paths. Add the project root AFTER Lake sets its environment.
set -l lake_path (lake env printenv LEAN_PATH)
set -l path_status $status
if test $path_status -ne 0
    echo "Could not determine Lake's LEAN_PATH." >&2
    exit $path_status
end
set -l augmented_path (string join : (pwd) $lake_path)

lake env lean --version | tee $version_file

printf '[STEP] Compile support module\n' > $log
lake env env "LEAN_PATH=$augmented_path" lean -o LtomProbeSupport.olean $support >> $log 2>&1
set -l support_status $status

set -l compile_status 0
if test $support_status -eq 0
    printf '\n[STEP] Compile example to C (forces LCNF)\n' >> $log
    lake env env "LEAN_PATH=$augmented_path" lean -c $generated_c $source >> $log 2>&1
    set compile_status $status
else
    set compile_status $support_status
end

begin
    printf 'SUPPORT_EXIT_CODE=%s\n' $support_status
    printf 'EXAMPLE_EXIT_CODE=%s\n' $compile_status
    printf 'SOURCE=%s\n' $source
    printf '\n-- LTOM messages and diagnostics --\n'
    rg -n '\[LTOM\]|error:|warning:|exception:|panic:' $log; or true
end | tee $summary

if test $compile_status -eq 0
    if not rg -q '\[LTOM\] call:' $log
        echo 'NO_LTM_CALL_FOUND: compilation succeeded but the pass did not report an annotated call.' | tee -a $summary
        set compile_status 3
    end
end

printf '\nFull output: %s\nSummary: %s\nVersion: %s\n' $log $summary $version_file
exit $compile_status
