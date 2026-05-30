/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license text here)
*/

/*
NOTE: These Features are Not For Library user, These are for Building Library.  

This File Contains  
------------------

* Dot Production with 2D and 1D tensors  
* Dot Production with 1D and 1D tensors  
*/

#ifndef DOT_PROD_HPP
#define DOT_PROD_HPP

#include <iostream>
#include "../assets.hpp" // for same ecosystem
// we can call #include "tensor.hpp" also


template <typename T>
class dot{
    /*
    dot production class   
    --------------------
    Class for metrics multiplication for Tensors  
    NOTE: Only Works with Tensors visit /assets/numpy/tensor.hpp for Info.  

    Parameter
    ----------
        Constructor #1  
        --------------
        metrics: Tensor2D of T type, Mainly X.  
            tensor2D<double> X({{0.1, 3.2, 10.0}, {23.4, 12.2, 10.0}}); // just pass thing like this
        values: Tensor1D of T type, Mainly weights and outputs.  
            tensor1D<double> weights({10.2, 30.1, 1.3})
        
        NOTE: total length of values must be equal to metrics' total column length.  

        Returns
        -------
        output: with getOutput(),  
            Return Type - Tensor1D  

        Constructor #2
        --------------
        targets: Tensor 1D of T type.
            tensor1D<double> target({1.2, 0.1, 1.3})
        values: Tensor 1D of T type.
            tensor1D<double> weights({10.2, 30.1, 1.3})

        NOTE: total length of values must be equal to target's total length.  

        Returns
        -------
        output: with getOutput(),  
            Return Type - Tensor1D  
    
    
    For Whom
    --------
    This is Only for Library Core, and Special if you wan't to contribute to library.  
        

    */
    private:
        tensor1D<double> output; // calculated output tensor

    public:
    // For 2D x 1D Tensor metrics - Mainly For LinearRegression, LogisticRegression, Ridge, Lasso, ElasticNet
    dot(tensor2D<T> metrics, tensor1D<T> values){

        std::vector<int> metrics_shape = metrics.shape; // shape of metrics
        size_t values_len = values.size(); // length of 1D metrics

        // safty check to save memory leak if Index mismatch like metric's cols == length of 1D values
        if (metrics_shape[1] != values_len){
            throw std::out_of_range("Size Mismatch");
        }

        // O(n^2) Multiplication Algorithams (Fast 'cause of C++ :D)
        for(size_t row = 0; row < metrics_shape[0]; row++){
            double calcu = 0;
            for(size_t col = 0; col < metrics_shape[1]; col++){
                calcu += metrics.at(row, col) * values.at(col); // values
            }

            output.add(calcu); // adding calculcation to 1D tensor
        }

    }

    // For 1D x 1D tensors - for nothing actually
    dot(tensor1D<T> targets, tensor1D<T> values){
        if (targets.size() != values.size()){
            throw std::out_of_range("Size Mismatch");
        }
        size_t len = targets.size();
        double calcu = 0;

        for(size_t i =0; i < len; i++){
            double calc = targets.at(i) * values.at(i);
            calcu += calc;
        }

        // adding output
        output.add(calcu);
    }

    tensor1D<double> getOutput() const{
        return output;
    }

};

#endif