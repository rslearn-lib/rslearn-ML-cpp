/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license in LICENSE btw.)
*/

// HELLO All, Welcome to Another Tutorial, huh, too much I know.
/*
So, This is Transpose Class.

What is Transpose   
Totaly Convert Row to Col and Col will automaticly Convert to Row, we all know, we are smart, ik.

Example
=======

{
{1, 2, 3},
{4, 5, 6}
}

This is a 2x3 Grid, Transpose will change it to 3x2  

AFTER TRANPOSE
==============
{
{1, 4},
{2, 5},
{3, 6}
}

That's Much of Bore Theory Let's Move toward Sun The Code!!!!!
ik that's very much of energy but what can I do? :D

PLEASE, Don't Tell Spell Mistake, I don't Have an auto corrector like Beluga :)
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

NOTE: add .out if you use MacOS and .exe if you use Windows in the end on l_T.<ext>

// if in same directry where learn_T.cpp is
g++ learn_T.cpp -o l_T

// outside of learn/ folder
g++ learn/learn_T.cpp -o l_T

RUN

LINUX
./l_T

WINDOWS
./l_T.exe

MACOS
./l_T.out

*/

int main(){

    // You can Now Create Tensor From Vector Cellebrate yayyyy!

    std::vector<std::vector<int>> rawData = {{1, 2, 3}, {4, 5, 6}};

    // Creating Tensor 2D btw
    tensor2D<int> tensor(rawData); // externel Vector
    tensor.printData(); // Let's see what is cookin' under the hood.
    tensor.printShape();

    // Calling Tranpose, He is in Way.
    Transpose<int> T(tensor); // make sure to pass 2D, 1D be like :- why not me? :(

    // Getting our Money Back from Tranpose Class
    // Data == Money, we all know

    tensor2D<int> outputs = T.getValues();

    // Lets's see what happens
    outputs.printData();
    outputs.printShape();

    // Am I Funny or ediot? (spell mistake ik, But I'm too lazy to fix it :D)
    // So Tutorial Ends, go Homie buds :)
    // Build Something but Don't Break Anything :( Pleaseeee
    // Not only Code, sleep too, don't be like me :D

    return 0; // make sure to return idk why but do it's not need money :)
}