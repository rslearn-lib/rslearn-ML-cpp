/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license)
*/

#ifndef _BASE_CPP
#define _BASE_CPP

#pragma once

#include <iostream>
#include <vector>
#include "../assets/numpy/tensor.hpp" // only tensor might be needed

template <typename T>
void printV(const std::vector<T> vec){
    for(const auto& element : vec){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void shapeValidator(std::vector<T> first_vec,std::vector<T> second_vec){
    if(first_vec.size() != 2 || second_vec.size() != 2){
        throw "Something went wrong in Tensors Shape";
    }

    if (first_vec.size() != second_vec.size()){
        std::cout << "Fitted Shape" << " ";
        printV(first_vec);
        std::cout << "Got Shape"<< " ";
        printV(second_vec);
        throw "Regression was fitted on Diffrent shapes";
    }

}


#endif