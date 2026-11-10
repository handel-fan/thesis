# Understanding the Lean researcher's notes: TensorLib → MLIR

The researcher was very likely explaining **proof by reflection**, a technique that could let you prove that transformations of TensorLib expressions preserve their meaning.

This is directly relevant to your TensorLib → MLIR project. More importantly, his first page suggests a particular architecture for your compiler that is different from simply walking `Lean.Expr` and generating MLIR.

## 1. First page: Proof by reflection

I read his handwriting approximately as:

```text
Proof by reflection

e : Tensor  ──reflection──>  a : TensorAST

⟦a⟧ : Tensor

⟦Plus(x,y)⟧ := ⟦x⟧ + ⟦y⟧

e = ⟦reflection(e)⟧

optimize : TensorAST → TensorAST

⟦optimize(a)⟧ = ⟦a⟧
```

The double brackets `⟦a⟧` mean **interpret the expression represented by `a` to obtain its mathematical/computational meaning**.

### What he was describing

Imagine a TensorLib expression:

```lean
A + B
```

He proposes turning this into your own representation:

```text
Plus
 ├── A
 └── B
```

He calls that representation `TensorAST`.

It is a data structure that you define, containing precisely the tensor operations your compiler understands.

You then define a function that interprets this AST:

$$
\llbracket \operatorname{Plus}(A,B)\rrbracket
=
\llbracket A\rrbracket + \llbracket B\rrbracket
$$

In ordinary terms, interpreting the AST must mean exactly the same thing as evaluating the original tensor expression.

### The first equality

$$
\boxed{e=\llbracket\operatorname{reflection}(e)\rrbracket}
$$

This is the first important statement he wrote.

- `e` is the original tensor expression.
- `reflection(e)` constructs the corresponding `TensorAST`.
- `⟦reflection(e)⟧` interprets that AST back into a tensor value.

**The equality says that converting a tensor expression into your own AST does not change its meaning.**

Establishing this formally would give you a correctness property for the first translation.

### The second equality

$$
\boxed{\llbracket\operatorname{optimize}(a)\rrbracket=\llbracket a\rrbracket}
$$

This is arguably even more important.

Suppose your AST contains:

```text
Plus(A, Zero)
```

Your optimizer replaces it with:

```text
A
```

You could prove, once, that this transformation preserves the tensor's value, assuming `Zero` is the appropriate additive identity.

You could then apply this optimizer to arbitrary tensor expressions without manually proving each individual invocation correct.

This is why proof by reflection is useful: **you can write executable transformations over expression trees, and establish their correctness through proofs about those transformations.**

However, this second equality concerns a transformation of `TensorAST`. It is not yet a proof that generated MLIR behaves identically to the original Lean program. That requires another connection between the AST and MLIR semantics.

## 2. What metaprogramming and tactics have to do with this

There is an important distinction between the two types of expressions being discussed:

- `Lean.Expr` is Lean's own representation of an elaborated program.
- `TensorAST` would be your representation, containing only the tensor operations you choose to support.

Lean's metaprogramming facilities allow you to inspect `Lean.Expr`, recognize operations such as TensorLib addition, and construct your own `TensorAST`. This is documented functionality, not a hypothetical extension.

For example:

```text
Lean term: A + B
       │
       │ reflection
       ▼
TensorAST: Plus(A, B)
       │
       │ lowering
       ▼
MLIR: tensor addition
```

*Possible architecture inferred from his notes, not an existing TensorLib compiler.*

**A tactic could automate part of this process.** For instance, a custom tactic could inspect the original Lean expression, construct the corresponding tensor AST, and produce a proof that the two have the same meaning.

Lean checks the resulting proof with its kernel. The tactic doesn't get to declare an unproved equality true.

One crucial detail: `reflection` here is not an ordinary runtime function `Tensor → TensorAST`. Once a tensor has been evaluated, its value doesn't generally tell you which expression produced it. Reflection must inspect the expression *before evaluation*, through Lean's metaprogramming machinery.

## 3. Second page: Why he might prefer `Lean.Expr` over LCNF

I read the main diagram as:

```text
Lean.Expr ──────────────> TensorAST
    │                         │
    ▼                         ▼
   LCNF                     MLIR
    │
    └───────────────────────> MLIR
```

He also wrote `VeIR`, which is an actual project: [Verified Intermediate Representation](https://github.com/opencompl/veir), a Lean compiler infrastructure with an MLIR-style representation and optional formal verification.

His likely reasoning for recommending `Lean.Expr`:

`Lean.Expr` retains Lean's elaborated types, dependent types, and proof-relevant structure. That makes it a natural starting point for understanding a tensor expression and constructing a proof about it.

LCNF is closer to executable code, but its conversion deliberately erases proof information and simplifies dependent types. Lean's own LCNF documentation confirms this loss of type information.

So the tradeoff is:

| `Lean.Expr` | LCNF |
|---|---|
| Better access to original mathematical meaning and types | Better representation for executable code |
| More natural for proof-oriented transformations | Less direct connection to source-level proofs |
| More work to handle general functional-language constructs | Much of that compiler work has already been performed |

That would explain why a Lean researcher interested in verification favored `Lean.Expr`, despite recognizing your implementation burden.

At the bottom, I read something like *pointer analysis and dim analysis are difficult*. I suspect he was highlighting further compiler problems, especially when translating general code or understanding tensor dimensions, but I'm less confident about that handwriting.

## 4. Third page: `@[bar]` and automatically processing definitions

He wrote approximately:

```lean
@[bar]
def foo (x : Int) :=
  x + 1
```

Then something resembling:

```text
bar ≈ Lean Decl → MLIR
```

This likely describes a custom Lean attribute.

You could define an attribute such as `@[to_mlir]`, then mark functions that your compiler should process:

```lean
@[to_mlir]
def foo (x : Int) :=
  x + 1
```

Your metaprogram could find these marked declarations, retrieve their elaborated expressions, and translate them into MLIR. Lean explicitly supports custom attributes for triggering compile-time processing of declarations.

This gives you a practical way to identify entry points without requiring a separate source-code parser.

It does not solve how to compile `fun`, `match`, recursion, or arbitrary library calls.

## 5. What this means for your thesis

I think he was proposing something more interesting than simply a Lean-to-MLIR translator:

**Use `Lean.Expr` to extract a tensor computation into your own AST, then use Lean to establish that the extraction and selected transformations preserve its meaning.**

There are three distinct correctness problems:

1. **Reflection correctness:** the TensorAST means the same thing as the original TensorLib expression.
2. **Optimization correctness:** a transformation of TensorAST preserves its meaning.
3. **Lowering correctness:** the generated MLIR behaves like the TensorAST.

His first page explicitly illustrates the first two, not the third.

For your actual project, there are still substantial complications. TensorLib expressions may return errors, depend on shapes and dtypes, or use arbitrary Lean functions. Your tensor AST and its interpretation would need to represent the relevant behavior. In particular, a theorem about abstract tensor arithmetic does not automatically establish correctness for floating-point MLIR operations.

**My interpretation:** he recommended `Lean.Expr` because it is the representation from which you can most naturally connect TensorLib's original semantics to a proof-carrying translation. He was accepting more compiler implementation work in exchange for easier access to Lean's verification machinery.
