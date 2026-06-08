/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license text here)
*/

/*
NOTE: These Features are Not For Library user, These are for Building Library.  

This File Contains  
------------------

* Transpose 1D and 2D Tensors 

*/

#ifndef T_HPP
#define T_HPP

#pragma once
#include <iostream>
#include <vector>
#include "tensor.hpp"



template <typename T>
class CreateRawData{
    public:
        std::vector<std::vector<T>> CreateVec(size_t row, size_t col){
            // Covering some memory before someone else does :)
            std::vector<std::vector<T>> vec(col, std::vector<T>(row,0));
            return vec;
        }
};

template <typename T>
class Transpose{
    private:
        std::vector<std::vector<T>> rawData;

    public:
        Transpose(tensor2D<T> tensor){
            std::vector<size_t> shape = tensor.shape;
            CreateRawData<T> CreateVector;
            rawData = CreateVector.CreateVec(shape[0], shape[1]);

            // Logic to Make New Metrics Without Ruining Prev Tensor
            for(size_t row=0; row < shape[0]; ++row){
                for(size_t col=0; col < shape[1]; ++col){
                    rawData[col][row] = tensor.at(row, col);
                }
            }

        }

        tensor2D<T> getValues() const{
            tensor2D<T> Data(rawData);
            return Data;
        }
};

#endif