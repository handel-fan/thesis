
# TensorLib to MLIR POC

## Linear Projection

### Inputs

```text
x    = [[1.0, 2.0],
        [3.0, 4.0]]       Shape: [2, 2]

w    = [[0.5, 1.0],
        [1.5, 2.0]]       Shape: [2, 2]

bias = [0.1, 0.2]         Shape: [2]
```

### Lean (TensorLib)

```lean
let y <- Tensor.Ufunc.matmul x w
let y <- Tensor.Ufunc.add y bias
```

### Output

```text
y = [[3.6, 5.2],
     [7.6, 11.2]]       Shape: [2, 2]
```

### Explanation

* Simple concept, for feed forward, etc

### MLIR

```mlir
func.func @linear_projection(%x: tensor<2x2xf32>,
                             %w: tensor<2x2xf32>,
                             %bias: tensor<2xf32>) -> tensor<2x2xf32> {
  %product = stablehlo.dot %x, %w
      : (tensor<2x2xf32>, tensor<2x2xf32>) -> tensor<2x2xf32>
  %bias_broadcast = stablehlo.broadcast_in_dim %bias, dims = [1]
      : (tensor<2xf32>) -> tensor<2x2xf32>
  %y = stablehlo.add %product, %bias_broadcast : tensor<2x2xf32>
  return %y : tensor<2x2xf32>
}
```

### Explanation

* multiply, make the bias vector same dim as matrix
(repeatedly join together rows (which is what dim = \[1\] specifies, row and not
columns)), then add

## Attention Score

### Inputs

```text
q = [[1.0, 2.0],
     [3.0, 4.0]]          Shape: [2, 2]

kT = [[1.0, 2.0],
      [3.0, 4.0]]         Shape: [2, 2]

scale = 8.0               Shape: [] (scalar)
```

### Lean (TensorLib)

```lean
let scores <- Tensor.Ufunc.matmul q kT
let scores <- Tensor.Ufunc.div scores scale
```

### Output

```text
scores = [[1.0, 2.0],
          [3.0, 4.0]]     Shape: [2, 2]
```

### Explanation

* q is query, kT is key transposed
* This step computes attention scores, measuring token matching between tokens
* scale is computed from the square root of the head dimension (sqrt(64) = 8)

### MLIR

```mlir
func.func @attention_score(%q: tensor<2x2xf32>,
                           %kT: tensor<2x2xf32>,
                           %scale: tensor<f32>) -> tensor<2x2xf32> {
  %product = stablehlo.dot %q, %kT
      : (tensor<2x2xf32>, tensor<2x2xf32>) -> tensor<2x2xf32>
  %scale_broadcast = stablehlo.broadcast_in_dim %scale, dims = []
      : (tensor<f32>) -> tensor<2x2xf32>
  // This is essentially creating a matrix the same size as product filled with
     scale to prep for division
  %scores = stablehlo.divide %product, %scale_broadcast : tensor<2x2xf32>
  return %scores : tensor<2x2xf32>
}
```

### Explanation

* q and kT are multiplied
* Then we need an entire matrix the same size as product, so broadcast one
* Lastly, divide elementwise
