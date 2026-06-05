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
    `#include "assets/assets.hpp"`  

    Initlization
    ------------

    `tensor1D<double> tensor({1.2, 1.0, 3.5, 10.0});`  

    Things to Remember
    ------------------
    * Use Dtype double or float for better gradient  
    * Input array not be Empty or better way to use externel array or vector like  
        `double arr[5] = {1.2, 1.0, 3.5, 10.0, 15.1}`  
        `tensor1D<double> tensor(arr)`  
    * array type and tensor type must be match double or int, double recommanded
    * Float is default  

    Features/Methods/attribute  
    --------------------------
    * shape (attribute) -> returns vector {rows, col}, usage `tensor.shape`, Dtype=vector<size_t>  
    * total_sum (attribute) -> return total sum of Tensor1D after sum(), usage `tensor.total_sum`, Dtype=T    
    * at (Method) Input(index) -> returns value at index, usage tensor.at(2), Dtype=T    
    * size (Method) -> returns total length of tensor same as shape[0], usage `tensor.size()`, Dtype=size_t    
    * sum (Method) -> calculate sum of Tensor, usage tensor.sum(false), Dtype=Nope  

Tensor 2D
---------
Core Data Structure for Data Processing and mainly for `X`  
    Importation
    -----------
    `#include "assets/numpy/tensor.hpp"`  
    `#include "assets/assets.hpp"`  

    Initlization
    ------------
    
    `tensor2D<double> tensor({{1.0, 2.4, 3.3}, {4.2, 5.5, 6.1}})`  

    Things To Remmember
    -------------------
    * No Empty Array for stability and clear control & Better Way to Write  
        `double arr[2][3] = {{1.0, 2.4, 3.3}, {4.2, 5.5, 6.1}}`  
        `tensor2D<double> tensor(arr)`  
    * array type and tensor type must be match double or float or int, float/double recommanded  
    * float is default

    Features/Methods/attribute  
    --------------------------
    * shape (attribute) -> returns vector {rows, col}, usage `tensor.shape`, dtype=vector<size_t>    
    * at (Method) Input(row, col) -> returns value at index= (row*total_col) + col, usage tensor.at(1, 2), Dtype=T    
    * size (Method) -> returns total length of tensor same as shape[0], usage `tensor.size()`, Dtype=size_t  
    * sum (Method) Input(axis=2/0/1) -> return 1D tensor of sum according to axis, usage `tensor.sum(axis=0/1)`, Dtype=tensor<T>  

    Axis
    ----
    axis 2 Default:
            Total Sum 
            {{1, 2}, {3, 4}} = 10
    axis 0 Column-wise:
            like 1+3, 2+4 = {4, 6}
    axis 1 Row-wise:
            like 1+2, 3+4 = {3, 7}
    
    Thank You!


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
template <typename T = float>
class tensor1D {
    private:
        std::vector<T> data;
    public:
        int ndim = 1;
        std::vector<size_t> shape = {0, 0};
        T total_sum = 0; // Sum We Might use

        tensor1D(T value){
            data.push_back(value);
            shape[0] = 1;
        }

        tensor1D() = default;

        tensor1D(std::vector<T> vec_input){
            if(vec_input.size() == 0){
                throw std::out_of_range("Oh, Vector is Empty! Fill it with stuff.");
            }

            data = vec_input;
            shape = {vec_input.size(), 0};
        }
       
        tensor1D(std::initializer_list<T> list): data(list) {
            if (data.empty()){
                throw std::invalid_argument("Seriously? An empty array? Try tensor1D<Dtype> tensor() instead.");
            }
            shape[0] = data.size();
        } // Direct Case 

        template <size_t N>
        tensor1D(const T (&rawArray)[N]) : data(rawArray, rawArray + N) {
            if(data.size() == 0){
                throw std::out_of_range("Vector is Empty, Nope!");
            }

            shape[0] = data.size();
        }

        void printData() const{
            for (const auto& item : data){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }

        void printShape() const{
            std::cout << "Size: " << shape[0] << std::endl;
        }

        T at(size_t index) const{
            if (index >= shape[0]){
                throw std::out_of_range("Requested index is out of territory :)");
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

        void sum(bool in_place=false){
            /*
            NOTE: with in_place = False it will just return new value
            and if in_place = True, then good luck sholdier Tensor just wiped out :)
            */
            if(shape[0] == 1){ // safety check really annoyed :(
                total_sum = data[0];
            }
            else{
                for(size_t item=0; item < shape[0]; item++){
                    total_sum += data[item];
                }
            }
            // True Case Tensor Just Gonna Wiped Out.
            if (in_place) {
                data = {total_sum}; // tensor Data gone swapped with sum Oh, No!
                // I Have to Clear Memory Otherwise people will not use it!!
                data.shrink_to_fit(); // Done, Now people will use it :)
                shape = {1, 0};
            }
            else{
                // leave it
                // automaticly saved total_sum attribute
            }
            // If user Care about Tensor then sum will be store in sum attribute and called by Tensor1D.sum but
            // please call it after sum() plssss!
        }


};

// Tensor 2D class for rslearn-ml for X and Metrics data and normal processing.
// this is also core Data Sctructure in this project
// NOTE for contibuters: USE IT EVERYWHERE 'CAUSE WHOLE CLASSES USES IT too. btw
// and checkout Tensor 1D 
// rslearn-ML-cpp/assets/numpy/tensor.cpp -  tensor2D
template <typename T=float>
class tensor2D{
    private:
        std::vector<std::vector<T>> data;
    
    public:
        std::vector<size_t> shape;
        int ndim = 2; 

        // Case like tensor2D<int> data({{1, 2}, {3, 4}});
        tensor2D(std::initializer_list<std::vector<T>> list): data(list){
            if (data.empty()){
                throw std::invalid_argument("Tensor can't be empty, it needs Job!");
            }
            size_t rows = data.size();
            size_t col = data[0].size();
            shape = {rows, col};
        }

        template <size_t ROWS, size_t COLS>
        tensor2D(const T (&rawArray)[ROWS][COLS]){
            shape = {
                static_cast<size_t>(ROWS),
                static_cast<size_t>(COLS)
            };
            
            for(size_t i=0; i < ROWS; i++){
                data.emplace_back(
                    rawArray[i],
                    rawArray[i] + COLS
                );
            }

        }

        tensor2D(std::vector<std::vector<T>> vec_input){
            
            if(vec_input.size() == 0){
                throw std::out_of_range("Oh, Vector is Empty! Fill it with stuff.");
            }

            data = vec_input;
            shape = {vec_input.size(), vec_input[0].size()};

        }

        T at(size_t row, size_t col) const{
            if(row >= shape[0] || col >= shape[1]){
                throw std::out_of_range("Something is suspicious, please check given row & col again.");
            }
            return data[row][col];
        }

        size_t size() const{
            return shape[0];
        }

        void printShape() const{
            std::cout << "Rows: " << shape[0] << "\n";
            std::cout << "Columns: " << shape[1] << "\n";
        }

        void printData() const{
            for(size_t row = 0; row < shape[0]; ++row){
                for(size_t col = 0; col < shape[1]; ++col){
                    std::cout << data[row][col] << " ";
                }
                std::cout << "\n";
            }
        }

        tensor1D<T> sum(int axis=2){
            /*
            axis=2 then total sum, return 1 value tensor1D
            axis=0 then column wise sum usually return tensor1D with total column size
            axis=1 then row wise sum usually return tensor1D with total row size, Lecture = learn/learn_sum.cpp I swear, Its not boring :D
            */
            if(axis == 2){
                // Let's use Math 
                T total_sum = 0;
                // Yeah, Ik Im not good at DSA but It's O(n^2) yeah ik;
                for(size_t row=0; row < shape[0]; row++){
                    for(size_t col=0; col < shape[1]; col++){
                        total_sum += data[row][col];
                    }
                }

                // converting to our Trusty Tensor `Tensor1D` :)
                tensor1D<T> output(total_sum);
                return output;
            } 
            else if (axis == 0){
                /* Column-Wise */
                /*
                Lemme Explain it,
                {
                {1, 2, 3},
                {4, 5, 6}
                }

                output = {5, 7, 9} why, 'cause 1+4 = 5; 2+5 = 7; 3+6 = 9; 
                Ik you all already how this output came, but I like Teaching :)

                */
               tensor1D<T> outputs;

                for(size_t col=0; col < shape[1]; ++col){
                    T total_sum = 0;
                    for(size_t row=0; row < shape[0]; ++row){
                        total_sum += data[row][col]; // column wise logic
                    }
                    outputs.add(total_sum);
                }

                // returning
                return outputs;
            } 
            else if (axis == 1){
                /*
                Row-wise sum
                {
                {1, 2, 3},
                {4, 5, 6}
                }

                output = {6, 15} Im not gonna Explain it.
                */

                tensor1D<T> outputs;
                // I just yoinked it from above :)
                for(size_t row=0; row < shape[0]; row++){
                    T total_sum = 0;
                    for(size_t col=0; col < shape[1]; col++){
                        total_sum += data[row][col]; // Row wise logic
                    }
                    outputs.add(total_sum);
                }

                return outputs; // go Homie
            }

            tensor1D<T> outputs;

            return outputs; //Empty

        }

};

#endif