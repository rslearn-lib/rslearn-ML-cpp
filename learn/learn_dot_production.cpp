/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license text here)
*/

/*
NOTE: These Features are Not For Library user, These are for Building Library.  

This File Contains  
------------------

* Learn Dot Production with 2D and 1D tensors  
* Learn Dot Production with 1D and 1D tensors  
*/


#include <iostream>
#include "../assets/assets.hpp"
#include <vector>

// FOR USER IMPORT "assets/assets.hpp"
// NOTE: NOT FOR BEGINNERS, Beginners visit it's Python Verison to Contribute
// Minimum C++ Experience Needed ~1 year
// Python Version: https://github.com/rslearn-lib/rslearn-ML-py
// Website for it: https://rslearn-py.rslearnlib.workers.dev

// prerequisite Needed - Tensor1D & Tensor2D 
// visit /learn/learn_tensors.cpp


/*
COMPILE
tested in g++ 16.1.1 and latest C++

NOTE: add .out if you use MacOS and .exe if you use Windows in the end on l_dot.<ext>

// if in same directry where learn_dot_production.cpp is
g++ learn_dot_production.cpp -o l_dot

// outside of learn/ folder
g++ learn/learn_dot_production.cpp -o l_dot

RUN

LINUX
./l_dot

WINDOWS
./l_dot.exe

MACOS
./l_dot.out

*/

// FOR FOR INFO VISIT /assets/numpy/dot_prod.hpp HEADER

int main(){
    // Tensors To Test
    // 1D x 1D - almost no need, skipable
    tensor1D<double> values1({10.0, 12.2, 14.2});
    tensor1D<double> values2({13.2, 11.1, 14.1});
    // NOTE: Both Length Must be Same & Dtype must be same too
    // output length will be 3

    // Dot Production
    dot<double> calculation1D(values1, values2);

    // Output - tensor1D in double always
    tensor1D<double> output1D = calculation1D.getOutput();

    // printing output - with Inbuilt Function in Tensor1D and Tensor2D both
    output1D.printData();

    // 2D x 1D main case will be X, weights 
    tensor2D<double> X({
        {10.2, 10.3},
        {7.1, 7.4},
        {2.1, 2.3}
    });
    tensor1D<double> weight({1.4, 1.6});
    // NOTE: For this Case, total X columns length must be same as total weight length
    // output length will be 3

    // Dot Production
    dot<double> calculation2D(X, weight); //always 2D and then 1D

    // output - tensor1D in double always
    tensor1D<double> output2D = calculation2D.getOutput(); 

    // Prinint it too with InBuilt Method
    output2D.printData();

    // NOTE: COMPILE AND RUN THIS FILE AND MATCH OUTPUTS
    // First Output - {467.64}
    // Second Output - {30.37, 21.78, 6.62}
    // It prints value so it will display without Brackets
    // Thank You For Visiting

    return 0;
}