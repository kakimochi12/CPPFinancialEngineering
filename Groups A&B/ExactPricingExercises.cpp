// In this file, we aim to test these values and plug them into the program we made with Option Pricing for European Options.

// Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13337, P = 5.84628). 
// Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96557, P = 7.96557). 
// Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204058, P = 4.07326). 
// Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.17570, P = 1.24750).

#include <iostream>
#include "include/EuropeanOption.hpp"
#include "include/BatchPricer.hpp"
#include "include/Utility.hpp"
#include "include/Testing.hpp"

// g++ -fdiagnostics-color=always -g "ExactPricingExercises.cpp" src/*.cpp -Iinclude -o ExactPricingExercises.exe
//          ./ExactPricingExercises.exe

// Main block where we test code
int main()
{
    // Part A & B Batch TESTS! SINGLE EXACT PRICING
    TestBatch(1, 1.45, 120, 0.51, 4.5, 108);          // (batchID, T, K, sig, r, S)
    TestBatch(2, 1.0, 100.0, 0.2, 0.0, 100.0);           // T = time to expiry
    TestBatch(3, 1.0, 10.0, 0.50, 0.12, 5.0);            // K = strike price
    TestBatch(4, 30.0, 100.0, 0.30, 0.08, 100);          // sig = volatility
                                                         // r = risk free interest rate
                                                         // S = current stock price (where we wish to price the option)


    // Part C Option price for increasing Spot Prices (SPOT PRICES RANGE)
    TestSpotRangePricing(1.0, 100.0, 0.2, 0.0, 0.0);      // T, K, sig, r, b          b = r
                                                          // change meshArray(start, stop, step) stop is inclusive

    // Part D use our Batch Pricing function that will calculate option prices for each vector of values
    std::vector<std::vector<double>> paramMatrix = {
        {0.25, 65.0, 0.30, 0.08, 60.0, 0.08},      // Batch 1           (T, K, sig, r, S, b)  
        {1.0, 100.0, 0.2, 0.0, 100.0, 0.0},        // Batch 2
        {1.0, 10.0, 0.50, 0.12, 5.0, 0.12},        // Batch 3
        {30.0, 100.0, 0.30, 0.08, 100, 0.08}       // Batch 4
    };

    // vector of types for corresponding option batch
    std::vector<std::string> types  = {"C", "P", "C", "P"};            // DEFINE OPTION TYPE

    // store the price for each optiomn batch
    std::vector<double> price = PriceOptionsBatch(paramMatrix, types);

    std::cout << "==== PART D: Matrix Batch Pricing ====\n";
    // loop through price vector and print its contents
    for (size_t i = 0; i < price.size(); ++i)
    {
        std::cout << "Option " << i+1 << "( " << types[i] << " ): Price = " << price[i] << "\n";
    }

    return 0;   
}