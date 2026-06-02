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

*/

#ifndef MATH_HPP
#define MATH_HPP

#pragma once

#include <iostream>
#include "../assets.hpp"
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

#endif