// Author: Kaiki Ikeda
// File: Exercise_3
// In this exercise we gained familiarity with an STL algorithm, specifically the count_if function that takes a start, end and a threshold.
// we originally made a global function and hard coded the threshold and saw how count_if can take in passed functions for threshold.
// we also created our own class isSmaller to experiment how the count_if takes in a class and is still able to run with the program.

#include "Countif.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


// Global checking function returns Bool
bool isSmallerValue(double input)
{
    return input < 5.0;                                 // return True of input is < 5.0 else False
}

int main()
{
    // ============================
    // Testing the global function
    // ============================  

    std::vector<double> a_vector = {2.0, 3.0, 6.0, 5.0};
    int count = std::count_if(a_vector.begin(), a_vector.end(), isSmallerValue);
    std::cout << "There are " << count << " elements smaller than 5.0." << std::endl;

    // ==============================
    // Testing our function object
    // ==============================

    std::vector<double> another_vector = {2.0, 9.0, 27.0, 26.0, 24.0, 42.0, 82.0, 62.0};                // initialize a vector

    isSmaller functor(20.0);                                                                            // create an object with parameterized constructor 
    int another_count = std::count_if(another_vector.begin(), another_vector.end(), functor);           // count_if to count values < 20.0
    std::cout << "Testing our function object, here is the result: " << another_count << std::endl;     // print our result

    return 0;   // indicates a successfully ran program.
}