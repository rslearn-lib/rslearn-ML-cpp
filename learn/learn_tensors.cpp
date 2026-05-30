/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license text here)
*/

#include <iostream>
#include "../assets/assets.hpp" // Importing for directry
#include <vector>

// FOR USER IMPORT "assets/assets.hpp"
// NOTE: NOT FOR BEGINNERS, Beginners visit it's Python Verison to Contribute
// Minimum C++ Experience Needed ~1 year
// Python Version: https://github.com/rslearn-lib/rslearn-ML-py
// Website for it: https://rslearn-py.rslearnlib.workers.dev


// COMPILE & RUN GUIDE
/*
COMPILE
tested in g++ 16.1.1 and latest C++

NOTE: add .out if you use MacOS and .exe if you use Windows in the end on l_tens.<ext>

// if in same directry where learn_tensors.cpp is
g++ learn_tensors.cpp -o l_tens

// outside of learn/ folder
g++ learn/learn_tensors.cpp -o l_tens

RUN

LINUX
./l_tens

WINDOWS
./l_tens.exe

MACOS
./l_tens.out

*/

int main(){

    // 1D testing

    int arry[] = {1, 2, 3};

    // Case one
    tensor1D<int> tens(arry); // externel array
    tens.printData();

    // Case Two

    tensor1D<int> tens2({10, 20, 30}); // init_list array
    tens2.printData();

    // Case Three
    tensor1D<int> tens3(67); // single value (only in 1D)
    tens3.printData();

    // std::cout << tens.shape() << std::endl;
    std::vector<int> shape = tens.shape;
    std::cout << shape[0] << std::endl;
    std::cout << tens.size() << std::endl;
    std::cout << tens.at(1) << std::endl;


    // 2D Testing
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    tensor2D<int> tens2d({{1, 2, 3}, {4, 5, 6}}); // init_list array case
    std::cout << tens2d.size() << std::endl;
    tens2d.printData();
    for(auto& item : tens2d.shape){
        std::cout << item << " ";
    }
    std::cout << "\n";


    std::cout << tens2d.at(1, 2) << std::endl; 

    tensor2D<int> tens2d2(arr); // externel array
    std::cout << tens2d2.size() << std::endl;
    tens2d2.printData();
    for(auto& item : tens2d2.shape){
        std::cout << item << " ";
    }
    std::cout << "\n";


    std::cout << tens2d2.at(1, 2) << std::endl;
    return 0;
}