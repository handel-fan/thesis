import Lean

open Lean
open Lean.Compiler.LCNF

-- Imported by the example; an initializer-defined attribute cannot be
-- registered and used in the same module under Lean 4.33.
initialize ltomAttr : TagAttribute ←
  registerTagAttribute `ltom_handel
    "Treat this function as an opaque TensorLib-to-MLIR operation"

-- Only examine the call site. Never inspect the implementation of the
-- annotated function.
private def inspectLtomCalls (code : Code .pure) : CompilerM Unit :=
  code.forM fun node => do
    match node with
    | .let binding _ =>
      match binding.value with
      | .const fn _ args _ =>
        if ltomAttr.hasTag (← getEnv) fn then
          let info ← getConstInfo fn
          logInfo m!"[LTOM] call: {fn}"
          logInfo m!"[LTOM] original type: {info.type}"
          logInfo m!"[LTOM] result binder: {binding.binderName}"
          logInfo m!"[LTOM] argument count: {args.size}"
      | _ => pure ()
    | _ => pure ()

private def ltomPass : Pass :=
  Pass.mkPerDeclaration `ltomPass .base fun decl => do
    decl.value.forCodeM inspectLtomCalls
    return decl

-- Before optimization/specialization: the first opportunity inside LCNF.
@[cpass] meta def installLtom : PassInstaller :=
  PassInstaller.installAfter .base `init (fun _ => ltomPass)
