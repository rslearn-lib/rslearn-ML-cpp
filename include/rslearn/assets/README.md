# rslearn-ML (C++), /assets
> Basic NumPy and Pandas Features in C++ to build Library

**a.k.a Base of Library :)**  

## Things Contains
### Tensors
Basic arrays bundled with shape, size, sum etc features
- Tensor1D
- Tensor2D

**Source Code: /assets/numpy/tensor.hpp**

### Transpose
To trapose Array like ndarrat.T()
- For 2D Tensors Only

**Source Code: /assets/numpy/T.hpp**

### Metrics Multiplication
a.k.a dot production, this is core for ML calculation
- Tensor2D x Tensor1D
- Tensor1D x Tensor1D

**Source Code: /assets/numpy/dot_prod.hpp**

### Sum
same as Tensor.sum()
- Tensor2D, with axis (also in Tensor.sum)
- Tensor1D, with in_place(also in Tensor.sum)

### Mean
It just Return Average of Tensor Based on axis (In 2D)
- Tensor1D
- Tensor2D, with axis (Default=2)

**Source Code: /assets/numpy/maths.hpp**

## How to Use?
**Visit: /learn/**