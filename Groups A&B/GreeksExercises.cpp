// This part will show the answers to the Greeks Exercises

// g++ -fdiagnostics-color=always -g GreeksExercises.cpp src/*.cpp -Iinclude -o GreeksExercises.exe
//    ./GreeksExercises.exe


#include <iostream>
#include "include/EuropeanOption.hpp"
#include "include/NumericalGreeks.hpp"
#include "include/BatchPricer.hpp"
#include "include/Utility.hpp"
#include "include/Testing.hpp"

int main()
{
    std::cout << "THIS PART IS THE TEST FOR GREEKS EXERCISES" << "\n";
    std::cout << "===================\n";
    std::cout << "PART A: Exact Delta & Gamma for Call and Put\n";
    std::cout << "===================\n";
    TestExactGreeks(1.45, 120, 0.51, 4.5, 108, 0.0, "P");    // T, K, sig, r, S, b, optionType
    TestExactGreeks(0.5, 100.0, 0.36, 0.1, 105.0, 0.0, "P");

    std::cout << "\n===================\n";
    std::cout << "PART B: Exact Delta over Spot Range\n";
    std::cout << "===================\n";
    TestExactDeltaOverSpotRange(0.5, 100.0, 0.36, 0.1, 0.0, "C");    // T, K, sig, r, b, optionType
                                                                     // change range in Testing.cpp for meshArray(start, stop, step) stop inclusive

    std::cout << "\n===================\n";
    std::cout << "PART C: Exact Sensitivities in Batch\n";
    std::cout << "===================\n";
    TestExactSensitivityBatch();                              // change valyes in testing.cpp Line 102             

    std::cout << "\n===================\n";
    std::cout << "PART D: Numerical Approximations\n";
    std::cout << "===================\n";
    TestNumericalGreeks(0.5, 100.0, 0.36, 0.1, 105.0, 0.0, "C", 0.1);  // T, K, sig, r, S, b, optionType, h
    TestNumericalGreeks(0.5, 100.0, 0.36, 0.1, 105.0, 0.0, "P", 0.1);

    std::cout << "\n-- Delta over Spot (Numerical) --\n";
    TestNumericalGreeksOverSpot(0.5, 100.0, 0.36, 0.1, 0.0, "C", 0.1);

    std::cout << "\n-- Batch Sensitivities (Numerical) --\n";
    TestSensitivityBatch(0.1);

    return 0;
}