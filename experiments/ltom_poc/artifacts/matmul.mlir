module {
  func.func @matmul(%x: tensor<2x2xf32>, %y: tensor<2x2xf32>) -> tensor<2x2xf32> {
    %z = stablehlo.dot %x, %y : (tensor<2x2xf32>, tensor<2x2xf32>) -> tensor<2x2xf32>
    return %z : tensor<2x2xf32>
  }
}
