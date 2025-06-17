// Author: Kaiki Ikeda
// File: Exercise_4
// This program we made a Stack Class through composition. We use Array as a member value for Stack and create stack to have unique
// function operations like Push and Pop. In the main program we tested these functions and also put some exceptions if Pop or Push was
// exercised when Stack is already full or empty.

#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class definition 
#include "ArrayException.hpp"      // Include custom exception classes for Array
#include "NumericArray.hpp"        // Include source file for numeric array 
#include "PointArray.hpp"          // include source file for PointArray
#include "Stack.hpp"               // include source file for Stack

#include <iostream>                // For std::cout and std::endl


int main()
{   
    // ===============================
    // Test Stack with Integer
    // ===============================

    Stack<int> stack1(3);

    try
    {
        std::cout << "Pushing elements: 2, 3, 4" << std::endl;
        stack1.Push(2);
        stack1.Push(3);
        stack1.Push(4);

        std::cout << "Popped Value: " << stack1.Pop() << std::endl;
        std::cout << "Popped Value: " << stack1.Pop() << std::endl;
        std::cout << "Popped Value: " << stack1.Pop() << std::endl;

        // This should throw an exception
        std::cout << "Attempting to Pop from an empty stack..." << std::endl;
        stack1.Pop();
    }
    catch(const std::underflow_error& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to overfill the stack..." << std::endl;
        stack1.Push(5);
        stack1.Push(6);
        stack1.Push(7);
        stack1.Push(8); // This should throw an overflow exception
    }
    catch(const std::overflow_error& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    
    return 0; // Indicates a successfully ran program
}
