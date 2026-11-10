
## Softmax

### Inputs

```text
scores = [[1.0, 2.0],
          [3.0, 4.0]]     Shape: [2, 2]
```

### Lean (TensorLib)

```lean
let exps <- Tensor.Ufunc.exp scores
let totals <- Tensor.Ufunc.sum exps (some [1])
```

### Output

```text
exps = [[2.718, 7.389],
        [20.086, 54.598]]   Shape: [2, 2]

totals = [10.107, 74.684]   Shape: [2]
```

### MLIR

```mlir
func.func @softmax_partial(%scores: tensor<2x2xf32>)
    -> (tensor<2x2xf32>, tensor<2xf32>) {
  %exps = stablehlo.exponential %scores : tensor<2x2xf32>
  %zero = stablehlo.constant dense<0.0> : tensor<f32>
  %totals = stablehlo.reduce(%exps init: %zero)
      applies stablehlo.add across dimensions = [1]
      : (tensor<2x2xf32>, tensor<f32>) -> tensor<2xf32>
  return %exps, %totals : tensor<2x2xf32>, tensor<2xf32>
}
```
