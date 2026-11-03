%A = arith.constant dense<[1.0, 2.0], [3.0, 4.0]]> : tensor<2x2xf32>
%B = arith.constant dense<[5.0, 6.0], [7.0, 8.0]]> : tensor<2x2xf32>
%C = arith.constant dense<0.0> : tensor<2x2xf32>


linalg.matmul
  ins(%A, %B : memref<2x2xf32>, memref<2x2xf32>)
  outs(%C : memref<2x2xf32)
