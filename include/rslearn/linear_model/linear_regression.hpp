/*
* Copyright (c) 2026, rslearn-lib, rslearn-ML
* All rights reserved.
* (Full BSD-3-Clause license)
*/

// Main File For LinearRegression Class Header btw.

#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector> // just in case 
#include "../assets/assets.hpp"
#include "../base/_base.cpp"

class LinearRegression{
    private:
        bool _fitted = false;
        std::string type = "regression";
        std::vector<size_t> fitted_shape;
    
        tensor1D<float> random_weight(size_t n_features){
            tensor1D<float> output;
            for(size_t i=0; i<n_features; i++){
                output.add(0.5); // 0.5 might be best
            }
            return output;
        }

        float mse(tensor1D<float> y_true, tensor1D<float> y_pred){
            tensor1D<float> loss = sub_tensor(y_pred, y_true);
            loss.square();
            size_t size = loss.size();

            loss.sum(true); //in_place

            float output = loss.at(0)/ static_cast<float>(size);

            return output;
        }

        tensor1D<float> return_dw(tensor2D<float> X, tensor1D<float> loss, size_t n_samples){
            Transpose<float> T_X(X);
            tensor2D<float> Trans_X = T_X.getValues(); // Have you Notic? it's T_X :D
            dot<float> D_X(Trans_X, loss);

            tensor1D<float> output = D_X.getOutput(); //Again D_X 

            output.multiply(2.0f/n_samples);

            return output;

        }

        float return_db(tensor1D<float> loss, size_t n_samples){
            loss.sum(true);
            loss.multiply(2.0f/n_samples);

            return loss.at(0);
        }
    
    public:
        tensor1D<float> fitted_weights;
        float fitted_bias;

        void fit(tensor2D<float> X, tensor1D<float> y, float min_loss=0.2, int max_itr=1500, float lr = 0.01f){

            if(y.shape[0] == 0){
                throw std::out_of_range("Y is Completely Nope!");
            }

            if(X.size() != y.size()){
                // Shape Mismatch
                throw std::out_of_range("Shape Mismatch, have you used added extra samples or labels? check those again!");
            }

            fitted_shape = X.shape;

            tensor1D<float> weights = random_weight(fitted_shape[1]);
            float bias = 0.2;

            int iteration = 0;

            while (iteration < max_itr){

                dot<float> calculate_dot(X, weights);
                tensor1D<float> pred = calculate_dot.getOutput();
                pred.add_val(bias); // y = M1X1 + M2X2 + ... + MnXn + bias

                float mse_error = mse(y, pred);

                if(mse_error <= min_loss){
                    std::cout << "Model Trained Successfully at Iteration #" << iteration << std::endl;
                    break;
                }

                tensor1D<float> loss = sub_tensor(y, pred);

                tensor1D<float> dw = return_dw(X, loss, fitted_shape[0]);

                float db = return_db(loss, fitted_shape[0]);

                dw.multiply(lr);
                
                weights = sub_tensor(dw, weights);
                bias -= lr * db;

                iteration++;
            }

            fitted_weights = weights;
            fitted_bias = bias;
            weights.printData();
            std::cout << bias << "\n";

            // std::cout << "Trained !" << std::endl;
            _fitted = true;

        }


        tensor1D<float> predict(tensor2D<float> X_new){
            // NOT FITTED CASE 
            if(!(_fitted)){
                throw "Regression haven't fitted yet.";
            }

            // INVALID SHAPE, Check you're data thausand time before giving to my Algorithms :)
            std::vector<size_t> new_shape = X_new.shape;

            shapeValidator(fitted_shape, new_shape);

            dot<float> calculate_dot(X_new, fitted_weights);
            tensor1D<float> pred = calculate_dot.getOutput();
            pred.add_val(fitted_bias); // y = M1X1 + M2X2 + ... + MnXn + bias

            return pred;
        }

        
};

#endif