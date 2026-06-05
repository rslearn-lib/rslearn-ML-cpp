/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license)
*/

/*
NOTE: This code is Written By ChatGPT, 'cause idk how to do this :)
Code is not tested yet, so not for use

Lines that I wrote basicly Changed 

24, include assets.hpp :)  
converted X, y to Tensor  
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <utility>

#include "../assets.hpp" // I wrote it :) 'cause chatGPT don't know I have a Tensor

std::string trim(const std::string &s) {
    int l = 0;
    int r = static_cast<int>(s.size()) - 1;

    while (l <= r && std::isspace(static_cast<unsigned char>(s[l]))) l++;
    while (l <= r && std::isspace(static_cast<unsigned char>(s[r]))) r--;

    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

float convertToken(const std::string &token) {
    std::string t = trim(token);

    try {
        size_t idx = 0;
        float val = std::stof(t, &idx);
        if (idx == t.size()) return val;
    } catch (...) {
        // ignore
    }

    float sum = 0.0f;
    for (char c : t) {
        sum += static_cast<int>(c);
    }
    return sum;
}

std::pair<tensor2D<float>, tensor1D<float>>
readCSV(const std::string &filename) {

    std::ifstream file(filename);

    std::vector<std::vector<float>> X;
    std::vector<float> y;

    std::string line;
    bool headerSkipped = false;

    while (std::getline(file, line)) {

        if (!headerSkipped) {
            headerSkipped = true;
            continue;
        }

        std::stringstream ss(line);
        std::string cell;

        std::vector<float> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(convertToken(cell));
        }

        if (row.empty()) continue;

        y.push_back(row.back());
        row.pop_back();

        X.push_back(row);
    }

    // my code started from here

    // Converting y to out trusty Tensor1D Oh my Dear <3
    tensor1D<float> labels(y);

    // Converting X to Tensor2D 
    tensor2D<float> features(X);

    return {features, labels}; // returning as pair idk why, but I tried thing like python X, y it didn't work PAINNNN! :(
}