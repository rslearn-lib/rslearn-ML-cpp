/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license text here)
*/

// File to Create Tensor in C++ 
// like np.array named as tensor


// HOW TO USE IT?

/*
CONTRIBUTER & DEVELOPER GUID   
RECOMMANDED EXPERIENCE IN C++ : atleast 1 years  
NOTE: THIS GUID IS NOT FOR BEGINNERS

*/

/*
It's Simple to use it

Tensor 1D
----------
Core Data Structure Used for `y` and dot production's output & `weights`

    importation
    -----------
    `#include "assets/numpy/tensor.hpp"`  

    Initlization
    ------------

    `tensor1D<double> tensor({1.2, 1.0, 3.5, 10.0});`  

    Things to Remember
    ------------------
    * Use Dtype double for better gradient  
    * Input array not be Empty or better way to use externel array like  
        `double arr[5] = {1.2, 1.0, 3.5, 10.0, 15.1}`  
        `tensor1D<double> tensor(arr)`  
    * array type and tensor type must be match double or int, double recommanded

    Features/Methods/attribute  
    --------------------------
    * shape (attribute) -> returns vector {rows, col}, usage `tensor.shape`  
    * at (Method) Input(index) -> returns value at index, usage tensor.at(2)  
    * size (Method) -> returns total length of tensor same as shape[0], usage `tensor.size()`  

Tensor 2D
---------
Core Data Structure for Data Processing and mainly for `X`  
    Importation
    -----------
    `#include "assets/numpy/tensor.hpp"`  

    Initlization
    ------------
    
    `tensor2D<double> tensor({{1.0, 2.4, 3.3}, {4.2, 5.5, 6.1}})`  

    Things To Remmember
    -------------------
    * No Empty Array for stability and clear control & Better Way to Write  
        `double arr[2][3] = {{1.0, 2.4, 3.3}, {4.2, 5.5, 6.1}}`  
        `tensor2D<double> tensor(arr)`  
    * array type and tensor type must be match double or int, double recommanded

    Features/Methods/attribute  
    --------------------------
    * shape (attribute) -> returns vector {rows, col}, usage `tensor.shape`  
    * at (Method) Input(row, col) -> returns value at index= (row*total_col) + col, usage tensor.at(1, 2)  
    * size (Method) -> returns total length of tensor same as shape[0], usage `tensor.size()`  



*/

#ifndef TENSOR_HPP
#define TENSOR_HPP

#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>


// Tensor 1D class for rslearn-ml for y and output data and normal processing
// this is core Data Sctructure in this project
// NOTE for contibuters: USE IT
// and checkout Tensor 2D
// rslearn-ML-cpp/assets/numpy/tensor.cpp - tensor1D
template <typename T>
class tensor1D {
    private:
        std::vector<T> data;
        
    public:
        int ndim = 1;
        std::vector<int> shape = {0, 0};

        tensor1D(T value){
            data.push_back(value);
            shape[0] = 1;
        }

        tensor1D() = default;
       
        tensor1D(std::initializer_list<T> list): data(list) {
            if (data.empty()){
                throw std::invalid_argument("Tensor can't be empty");
            }
            shape[0] = data.size();
        } // Direct Case 

        template <size_t N>
        tensor1D(const T (&rawArray)[N]) : data(rawArray, rawArray + N) {
            shape[0] = data.size();
        }

        void printData() const{
            for (const auto& item : data){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }

        T at(size_t index) const{
            if (index >= shape[0]){
                throw std::out_of_range("Index Out Of Range");
            }

            return data.at(index);
        }

        size_t size() const{
            return shape[0];
        }

        void add(T val){
            data.push_back(val);
            shape[0]++;
        }
};

// Tensor 2D class for rslearn-ml for y and output data and normal processing
// this is also core Data Sctructure in this project
// NOTE for contibuters: USE IT EVERYWHERE 'CAUSE WHOLE CLASSES USES IT
// and checkout Tensor 1D 
// rslearn-ML-cpp/assets/numpy/tensor.cpp -  tensor2D
template <typename T>
class tensor2D{
    private:
        std::vector<std::vector<T>> data;
    
    public:
        std::vector<int> shape;
        int ndim = 2; 

        // Case like tensor2D<int> data({{1, 2}, {3, 4}});
        tensor2D(std::initializer_list<std::vector<T>> list): data(list){
            if (data.empty()){
                throw std::invalid_argument("Tensor can't be empty");
            }
            int rows = data.size();
            int col = data[0].size();
            shape = {rows, col};
        }

        template <size_t ROWS, size_t COLS>
        tensor2D(const T (&rawArray)[ROWS][COLS]){
            shape = {
                static_cast<int>(ROWS),
                static_cast<int>(COLS)
            };
            
            for(size_t i=0; i < ROWS; i++){
                data.emplace_back(
                    rawArray[i],
                    rawArray[i] + COLS
                );
            }

        }

        T at(size_t row, size_t col) const{
            if(row >= shape[0] || col >= shape[1]){
                throw std::out_of_range("Invalid row, col");
            }
            return data[row][col];
        }

        size_t size() const{
            return shape[0];
        }

        void printData() const{
            for(size_t row = 0; row < shape[0]; ++row){
                for(size_t col = 0; col < shape[1]; ++col){
                    std::cout << data[row][col] << " ";
                }
                std::cout << "\n";
            }
        }

};

#endif