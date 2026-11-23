import Probe

-- Deliberately unused Nat parameters: tests whether explicit metadata survives.
@[noinline]
def tensorTag (rows cols : Nat) {α : Type} (x : α) : α := x

@[noinline]
def matmul (a b : Nat) : Nat := a * b

-- Nat is a placeholder for the runtime TensorLib.Tensor value.
-- The experiment tests the wrapper's call structure, not tensor arithmetic.
@[noinline]
def work (x y : Nat) : Nat :=
  let a := tensorTag 2 2 x
  let b := tensorTag 3 4 y
  let product := matmul a b
  let c := tensorTag 2 4 product
  c

def main : IO Unit := do
  IO.println s!"RESULT={work 3 7}"
