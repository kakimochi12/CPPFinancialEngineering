// Author: Kaiki Ikeda
// File: Exercise_2
// This program tests exception handling for accessing an out-of-bounds element in the Array class.
// It uses the ArrayException base class and its derived OutOfBoundsException class to demonstrate polymorphic behavior.

#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class definition
#include "ArrayException.hpp"      // Include custom exception classes for Array

#include <iostream>                // For std::cout and std::endl

int main()
{
    try
    {
        Array arr1; // Create an Array object with default size (usually 10)
        
        // Try to access an out-of-bounds index (-11), which will throw an OutOfBoundsException
        std::cout << "Test for out of bounds: " << arr1.GetElement(-11) << std::endl;
    }
    catch(const ArrayException &arr_exception) // Catch any exception derived from ArrayException
    {
        // Print the specific error message from the exception
        std::cout << "Error: " << arr_exception.GetMessage() << std::endl;
    }

    return 0; // Indicates a successfully run program
}
