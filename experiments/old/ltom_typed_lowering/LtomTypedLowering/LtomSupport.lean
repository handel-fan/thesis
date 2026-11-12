import Lean
import LtomTypedLowering.EmitStableHLO


-- Register the annotation used to identify functions
-- that our compiler should translate into StableHLO.

initialize ltomAttr : Lean.TagAttribute ←
  Lean.registerTagAttribute
    (Lean.Name.mkSimple "ltom_handel")
    "Opaque TensorLib operation with a separately defined StableHLO lowering"


-- Determine which StableHLO lowering should be used
-- for a particular annotated function.

private def findLoweringCaseName
    (functionName : Lean.Name) : Option String :=

  let functionNameString : String := toString functionName

  if String.endsWith functionNameString "ltomAdd2x3" then
    Option.some "add2x3"

  else if String.endsWith functionNameString "ltomAdd2x2" then
    Option.some "add2x2"

  else if String.endsWith functionNameString "ltomMatmul2x3" then
    Option.some "matmul2x3"

  else
    Option.none


-- Generate StableHLO from the function's tensor specifications.

private def generateStableHLO
    (functionName : Lean.Name)
    (parameterSpecifications : Array LtomTypedLowering.TensorSpec)
    (resultSpecification : LtomTypedLowering.TensorSpec)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  match findLoweringCaseName functionName with

  | Option.none =>
    Lean.logError m!"[LTOM_ERROR] No lowering registered for {functionName}"

  | Option.some loweringCaseName =>

    match LtomTypedLowering.emitCase?
        loweringCaseName
        parameterSpecifications
        resultSpecification with

    | Option.none =>
      Lean.logError m!"[LTOM_ERROR] Lowering contract mismatch: {loweringCaseName}"

    | Option.some generatedMLIR =>
      Lean.logInfo m!"[LTOM_MLIR] {loweringCaseName}|{generatedMLIR}"


-- Print the MLIR type of every parameter and the result.

private def reportTensorTypes
    (functionName : Lean.Name)
    (parameterSpecifications : Array LtomTypedLowering.TensorSpec)
    (resultSpecification : LtomTypedLowering.TensorSpec)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  for parameterIndex in List.range (Array.size parameterSpecifications) do

    match Array.get? parameterSpecifications parameterIndex with

    | Option.some parameterSpecification =>
      let parameterMLIRType : String :=
        LtomTypedLowering.TensorSpec.mlirType parameterSpecification

      Lean.logInfo m!"[LTOM_PARAM] {functionName} index={parameterIndex} type={parameterMLIRType}"

    | Option.none =>
      Lean.logError m!"[LTOM_ERROR] Missing parameter at index {parameterIndex}"

  let resultMLIRType : String :=
    LtomTypedLowering.TensorSpec.mlirType resultSpecification

  Lean.logInfo m!"[LTOM_RESULT] {functionName} type={resultMLIRType}"


-- Extract tensor specifications from the original Lean
-- function signature and check the number of arguments.

private def inspectContract
    (functionName : Lean.Name)
    (originalDeclarationType : Lean.Expr)
    (numberOfLCNFArguments : Nat)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  match LtomTypedLowering.contract? originalDeclarationType with

  | Option.none =>
    Lean.logError m!"[LTOM_ERROR] Cannot extract a concrete TensorSpec contract for {functionName}"

  | Option.some (parameterSpecifications, resultSpecification) =>

    let numberOfDeclaredParameters : Nat :=
      Array.size parameterSpecifications

    if numberOfDeclaredParameters != numberOfLCNFArguments then
      Lean.logError m!"[LTOM_ERROR] Parameter/operand count mismatch for {functionName}: {numberOfDeclaredParameters} vs {numberOfLCNFArguments}"

    else
      reportTensorTypes
        functionName
        parameterSpecifications
        resultSpecification

      generateStableHLO
        functionName
        parameterSpecifications
        resultSpecification


-- Inspect a function call and check whether it has
-- the ltom_handel annotation.

private def inspectFunctionCall
    (functionName : Lean.Name)
    (functionArguments : Array (Lean.Compiler.LCNF.Arg Lean.Compiler.LCNF.Purity.pure))
    (resultVariableName : Lean.Name)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  let compilerEnvironment : Lean.Environment ← Lean.getEnv

  if Lean.TagAttribute.hasTag ltomAttr compilerEnvironment functionName then

    let functionInformation : Lean.ConstantInfo ←
      Lean.getConstInfo functionName

    let originalDeclarationType : Lean.Expr :=
      Lean.ConstantInfo.type functionInformation

    let numberOfLCNFArguments : Nat :=
      Array.size functionArguments

    Lean.logInfo m!"[LTOM] call: {functionName}"
    Lean.logInfo m!"[LTOM] declaration type: {originalDeclarationType}"
    Lean.logInfo m!"[LTOM] LCNF result: {resultVariableName}"
    Lean.logInfo m!"[LTOM] LCNF args: {numberOfLCNFArguments}"

    inspectContract
      functionName
      originalDeclarationType
      numberOfLCNFArguments

  else
    return ()


-- Examine the value assigned by an LCNF let instruction.
-- If that value is a direct function call, inspect it.

private def inspectAssignment
    (assignment : Lean.Compiler.LCNF.LetDecl Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  match assignment.value with

  | Lean.Compiler.LCNF.LetValue.const
      functionName
      universeLevels
      functionArguments
      proofOfPurity =>

    inspectFunctionCall
      functionName
      functionArguments
      assignment.binderName

  | otherAssignedValue =>
    return ()


-- Examine one LCNF instruction.

private def inspectCodeNode
    (codeNode : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM Unit := do

  match codeNode with

  | Lean.Compiler.LCNF.Code.let
      assignment
      remainingCode =>

    inspectAssignment assignment

  | otherCodeNode =>
    return ()


-- Walk through every LCNF instruction.

private def inspectCalls
    (code : Lean.Compiler.LCNF.Code Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM Unit :=

  Lean.Compiler.LCNF.Code.forM
    code
    inspectCodeNode


-- Run our inspection on one compiler declaration.
-- Return the declaration unchanged.

private def inspectDeclaration
    (declaration : Lean.Compiler.LCNF.Decl Lean.Compiler.LCNF.Purity.pure)
    : Lean.Compiler.LCNF.CompilerM
        (Lean.Compiler.LCNF.Decl Lean.Compiler.LCNF.Purity.pure) := do

  Lean.Compiler.LCNF.DeclValue.forCodeM
    inspectCalls
    declaration.value

  return declaration


-- Create the custom compiler pass.

private def ltomPass : Lean.Compiler.LCNF.Pass :=

  Lean.Compiler.LCNF.Pass.mkPerDeclaration
    (Lean.Name.mkSimple "ltomPass")
    Lean.Compiler.LCNF.Phase.base
    inspectDeclaration


-- Supply our custom pass to the pass installer.

private def selectLtomPass
    (previousPass : Lean.Compiler.LCNF.Pass)
    : Lean.Compiler.LCNF.Pass :=

  ltomPass


-- Register the pass so Lean automatically runs it
-- immediately after the initial LCNF pass.

@[cpass]
meta def installLtom : Lean.Compiler.LCNF.PassInstaller :=

  Lean.Compiler.LCNF.PassInstaller.installAfter
    Lean.Compiler.LCNF.Phase.base
    (Lean.Name.mkSimple "init")
    selectLtomPass
