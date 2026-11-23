# Real TensorLib identity-wrapper LCNF experiment

Uses real TensorLib.Tensor values, real matrix multiplication, and a `tensorTag` wrapper with explicit `(rows cols dtype)` metadata. Observes LCNF after `init` and at the end of the base phase, recording calls and literal bindings. Does not modify LCNF. The tagged function has a marked noinline boundary.

The program verifies the 2x2 matrix product and prints `TENSORLIB_OK`. Its successful execution is separate from confirming the LCNF metadata: inspect `[CALL/EARLY]` / `[CALL/LATE]` and `[LIT/*]` logs.

Run `python3 runner.py` on a system with Lean 4 / Lake and the indicated local thesis checkout. The runner discovers the Lake project from the thesis root or the TensorLib dependency checkout. Execution has not been tested here because Lean is not installed in this environment.
