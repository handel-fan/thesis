def square (x : Nat) : Nat :=
  x * x

def main : IO Unit := do
  IO.println (square 5)
