/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license in LICENSE btw.)
*/

// HELLO All, Welcome to Another Tutorial, Yeah one Another Tutorial and Don't worry there are hundreds to go :)
/*
Learn Sum
Yeah Ik you all were thinking I already know sum value but This is Diffrent you need to know 'cause ik yeah.

What is Sum
Adding value is sum just...

But in this case we gonna use it for tensors

For 1D Tensors

{1, 2, 3, 4} = 10 Okay? Yeah I did it without any calculator :)

For 2D Tensors

There are Threee Case

#1 Total Sum like a.k.a axis=2

{
{1, 2, 3},
{4, 5, 6}
}

sum = 21

#2 Row-wise a.k.a axis=1

{
{1, 2, 3},
{4, 5, 6}
}

sum = {6, 15} and Yeah it returns Tensor Holy promotion :)

#3 Column-wise a.k.a axis=0

{
{1, 2, 3},
{4, 5, 6}
}

sum = {5, 7, 9} and Another 1D tensor

Let's see it In Code
But there are to way to do it..

#1 Using Class Method and Yeah now it is a built in feature in tensors
#2 Diffrent Class
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

NOTE: add .out if you use MacOS and .exe if you use Windows in the end on l_sum.<ext>

// if in same directry where learn_sum.cpp is
g++ learn_sum.cpp -o l_sum

// outside of learn/ folder
g++ learn/learn_sum.cpp -o l_sum

RUN

LINUX
./l_sum

WINDOWS
./l_sum.exe

MACOS
./l_sum.out

*/

int main(){
    // Using Inbuilt Method

    // For 1D Oh My Trusted..

    tensor1D<int> tens1({1, 2, 3});

    // parameters - in_place = false it will wiped out whole Tensor and replace it with just one value which will be sum
    tens1.sum(); // in_place = false default
    std::cout << tens1.total_sum << std::endl;

    // tens1.sum(true)
    // tens1.printData()
    // tens1.printShape()

    // You can test these above if you want, ;)

    // By Class 
    sum<int> s(&tens1); // it had a in_place too which is false btw;
    tensor1D<size_t> outputs = s.outputs; // returns outputs as size_t tensor, btw in-future it gonna change to double
    outputs.printData();

    // you can do just pass true after tens1 and it's in place
    // sum<int> s(&tens1, true);
    // tens1.printData();
    // But Don't do that untill you know what are you doin'

    // 2D Tensors

    tensor2D<int> tens2({
        {1, 2, 3},
        {4, 5, 6}
    });

    // By Method
    tensor1D<size_t> outputF2 = tens2.sum(2); // as default axis total sum
    outputF2.printData(); // 21

    tensor1D<size_t> outputF1 = tens2.sum(1); // row-wise sum
    outputF1.printData(); // {6, 15}

    tensor1D<size_t> outputF0 = tens2.sum(0); // column-wise sum
    outputF0.printData(); // {5, 7, 9} if it is same on your computer too then thank god! phewwwwww....

    // By Class
    sum<int> s2(tens2, 2); //default
    tensor1D<size_t> outputs2 = s2.outputs;
    outputs2.printData(); // 21

    sum<int> s3(tens2, 1); // row-wise sum
    tensor1D<size_t> outputs1 = s3.outputs;
    outputs1.printData(); // {6, 15}

    sum<int> s4(tens2, 0); //default
    tensor1D<size_t> outputs0 = s4.outputs;
    outputs0.printData(); // {5, 7, 9}

    // And According to Human feeling I'm sure that you will use Inbuilt Methods and actually I will too :)
    

    return 0; // make sure to return idk why but do it's not need money :) x2, i don't remember anything to write here funny so...
}