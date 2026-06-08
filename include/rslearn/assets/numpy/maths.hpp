/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license)
*/

// File to Create Some NumPy Math Feature in C++ 
// like sum, mean, average, sub etc

/*
sum() :-
It will take Tensors

Case #1
Tensor2D, axis {0, 1, 2}

works same as tensor2D.sum(0) or 1 or 2

Case #2 
Tensor1D, in_place

Yeah, ik We have to think too much! :(

mean() :-
It will also eat Tensors.

Cases In it's class

*/

#ifndef MATH_HPP
#define MATH_HPP

#pragma once

#include <iostream>
#include "tensor.hpp"
#include <vector>

template <typename T>
class sum{
    public:
        tensor1D<T> outputs;
        // Case #2 First It's Simple so, don't ask why It took 1 hour idk. PAIN...
        sum(tensor1D<T>* data, bool in_place=false){
            /*
            NOTE: with in_place = False it will just return new value
            and if in_place = True, then good luck sholdier Tensor just wiped out :)

            and if you are here after reading line 157, 158 in numpy/tensors.hpp then
            you will notic that ... I just Copy paste :D
            */

            if (data == nullptr) return; // idk why i do this, I found it on best practices, Huh too much.

            T total_sum = 0;
            
            // total_sum = data->total_sum;

            // True Case Tensor Just Gonna Wiped Out.
            if (in_place) {
                data->sum(in_place); // I just forgot I had Implemented in Class It took whole time ah.
            }
            else{
                // if false as default
                data->sum();
                total_sum = data->total_sum;
                outputs.add(total_sum);
            }

        }
        // I think It's hard It took just 5 mins to be Done!!
        sum(tensor2D<T> data, int axis=2){
            if(axis == 2){
                outputs = data.sum(); //default = 2
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

                */
               
                outputs = data.sum(0); // Thanks God, I Implemented Class Method first for it

            } 
            else if (axis == 1){
                /*
                Row-wise sum
                {
                {1, 2, 3},
                {4, 5, 6}
                }

                output = {6, 15}
                */

                outputs = data.sum(1); //Ez
            }
        }
};

// Mean for Tensors, 1D & 2D
// Weight Support

// return type - Tensor<float> kinda default

template <typename T>
class mean{
    
    // First Constructor
    // Case #1, Tensor1D
    // Case #2, Tensor2D, axis, default as you know 2!
    
    private:
        tensor1D<float> output;

    public:
        

        // Tensor1D - return float value

        mean(tensor1D<T> tensor){
            if(tensor.size() == 0){
                throw std::out_of_range("Tensor is Nope!");
            }

            tensor.sum(); // Adding
            T output_1D = tensor.total_sum;
            

            float mean_1D = static_cast<float>(output_1D)/tensor.size();

            output.add(mean_1D);
        }   

        // Tensor2D return tensor1D<float>
        mean(tensor2D<T> tensor, int axis=2){
            if(axis==2){
                
                // Sum first
                T sum_2D = tensor.sum().at(0);

                // denominator - Fraction Time!!
                std::vector<size_t> shape = tensor.shape;
                int denom = shape[0] * shape[1]; // N*M = total Values

                // mean - what did you mean? :D
                float mean_2D = static_cast<float>(sum_2D)/ denom;

                output.add(mean_2D);
            }
            else if(axis==0){
                // sum as always
                tensor1D<T> sum_2D = tensor.sum(0);

                /*
                Sum May Look Like this
                [4, 6]

                for 
                [
                    [1, 2],
                    [3, 4]
                ]

                so divide them with? total Count Easy! and Total Count? Row!!!
                */

                size_t len = tensor.shape[0]; // rows len

                for(size_t i=0; i<sum_2D.size(); i++){
                    // DEVIDEEEE
                    float devided = sum_2D.at(i)/static_cast<float>(len);
                    output.add(devided);
                }

            }
            else if(axis=1){
                // SUMMMM
                tensor1D<T> sum_2D = tensor.sum(1);


                size_t denom = tensor.shape[1]; // total column kinda :)

                for(size_t i=0; i<sum_2D.size(); i++){
                    float devided = sum_2D.at(i)/static_cast<float>(denom);
                    output.add(devided);
                }
            }
            else{
                throw std::out_of_range("NOPE, You Entered Wrong axis!");
            }

        }

        tensor1D<float> getValue() const{
            return output;
        }
        
};

// Only For linear_model
tensor1D<float> sub_tensor(tensor1D<float> pred, tensor1D<float> y_true){
    if(pred.shape[0] != y_true.shape[0]){
        throw std::out_of_range("Internel Error: y_true & pred Shape Mismatch Found");
    }

    tensor1D<float> output;

    for(size_t i=0; i<pred.shape[0]; i++){
        float val = y_true.at(i) - pred.at(i);
        output.add(val);
    }

    return output;

}


#endif