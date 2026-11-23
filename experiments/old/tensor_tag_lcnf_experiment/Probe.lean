import Lean

/-
  Observational LCNF passes: do not modify declarations.
  EARLY: immediately after init in the base phase.
  LATE: end of the base phase.
-/
namespace TensorTagProbe

private def inspectCode (stage : String)
    (code : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure) :
    Lean.Compiler.LCNF.CompilerM Unit :=
  code.forM fun instruction => do
    match instruction with
    | Lean.Compiler.LCNF.Code.let binding _ =>
      match binding.value with
      | Lean.Compiler.LCNF.LetValue.const functionName _ operands _ =>
        if functionName == `tensorTag then
          Lean.logInfo m!"[TAG/{stage}] result={binding.binderName} type={binding.type}"
          for operand in operands do
            Lean.logInfo m!"[TAG/{stage}] arg={operand.toExpr}"
        else
          pure ()
      | Lean.Compiler.LCNF.LetValue.lit literal =>
        Lean.logInfo m!"[LIT/{stage}] binder={binding.binderName} literal={literal.toExpr}"
      | _ => pure ()
    | _ => pure ()

private def earlyPass : Lean.Compiler.LCNF.Pass :=
  Lean.Compiler.LCNF.Pass.mkPerDeclaration
    `tensorTagProbeEarly Lean.Compiler.LCNF.Phase.base
    fun declaration => do
      declaration.value.forCodeM (inspectCode "EARLY")
      return declaration

private def latePass : Lean.Compiler.LCNF.Pass :=
  Lean.Compiler.LCNF.Pass.mkPerDeclaration
    `tensorTagProbeLate Lean.Compiler.LCNF.Phase.base
    fun declaration => do
      declaration.value.forCodeM (inspectCode "LATE")
      return declaration

@[cpass] meta def installEarly : Lean.Compiler.LCNF.PassInstaller :=
  Lean.Compiler.LCNF.PassInstaller.installAfter
    Lean.Compiler.LCNF.Phase.base `init (fun _ => earlyPass)

@[cpass] meta def installLate : Lean.Compiler.LCNF.PassInstaller :=
  Lean.Compiler.LCNF.PassInstaller.installAtEnd
    Lean.Compiler.LCNF.Phase.base latePass

end TensorTagProbe
