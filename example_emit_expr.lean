import Lean

open Lean Elab Command

def main : IO Unit := do
  IO.println "Hello"
  IO.println "World"

run_cmd do
  let info ← getConstInfo ``main

  let expr ← match info.value? with
    | some expression => pure expression
    | none => throwError "main has no body"

  logInfo m!"{repr expr}"
