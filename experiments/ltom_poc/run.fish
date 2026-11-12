#!/usr/bin/env fish
set -l here (cd (dirname (status --current-filename)); and pwd)
set -l root (cd "$here/../.."; and pwd)
set -l art "$here/artifacts"
mkdir -p "$art"
cd "$root"; or exit 2
set -l lake_path (lake env printenv LEAN_PATH); or exit 2
set -l lean_path "$here:$lake_path"

function lean_poc
    set -l lean_path $argv[1]
    lake env env "LEAN_PATH=$lean_path" lean $argv[2..-1]
end

echo '[1/3] Compile support module'
lean_poc "$lean_path" -o "$here/LtomPocSupport.olean" "$here/LtomPocSupport.lean" > "$art/support.log" 2>&1
or begin
    cat "$art/support.log"
    exit 1
end

echo '[2/3] Compile Main to C (run early LCNF pass)'
lean_poc "$lean_path" -c "$art/Main.c" "$here/Main.lean" > "$art/compile.log" 2>&1
or begin
    cat "$art/compile.log"
    exit 1
end

grep -E '\[POC\]|\[SHLO\]' "$art/compile.log"

python3 -c 'from pathlib import Path
import re, sys
p = Path(sys.argv[1]); text=p.read_text(); hits=re.findall(r"\[SHLO\] ([^\r\n]+)",text)
if not hits: raise SystemExit("FAIL: no StableHLO emitted")
out=p.parent / "matmul.mlir"; out.write_text(hits[0].replace("@@NL@@", "\n")+"\n")
print("\n--- matmul.mlir ---\n"+out.read_text())' "$art/compile.log"
or exit 1

echo '[3/3] Execute real TensorLib matmul'
lean_poc "$lean_path" --run "$here/Main.lean" > "$art/runtime.log" 2>&1
or begin
    cat "$art/runtime.log"
    exit 1
end
cat "$art/runtime.log"
echo "POC COMPLETE: $art/matmul.mlir"
