// addressing the exercises for Perpetual Options on this file

// g++ -fdiagnostics-color=always -g PerpetualOptionsExercises.cpp src/*.cpp -Iinclude -o PerpetualOptionsExercises.exe
//    ./PerpetualOptionsExercises.exe


#include <iostream>
#include "include/Testing.hpp"

int main()
{
    std::cout << "==== PERPETUAL AMERICAN OPTIONS ====\n";
    std::cout << "\n Part B: Single Calculation \n";
    TestPerpetualPrice();                                      // change in testing.cpp line 188

    std::cout << " Part C: Perpetual Pricing over Spot Range\n";
    TestPerpetualOverSpotRange();                              // change in testing.cpp line 208

    std::cout << "Part D: Perpetual Option Batch Processing\n";
    TestPerpetualBatch();                                      // // change in testing.cpp line 229

    return 0;    // indicates a successfully ran program
}