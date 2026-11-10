import Lean

open Lean Elab Command

def square (x : Nat) : Nat := x * x

run_cmd do
  let env ← getEnv
  let some info := env.find? `square
    | throwError "Could not find square"

  let expr := info.value!
  logInfo m!"{repr expr}"
