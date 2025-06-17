// Author: Kaiki Ikeda
// File: Exercise_5
// In this exercise we made our own StacException class as a new header file. From the base class we derived one exception for a full stack
// and another exception for an empty stack. In the main program we tested how the program responds when we force a stack to be full or empty
// and continue operations on it. The program successfully returns our new derived exceptions.

#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class definition 
#include "ArrayException.hpp"      // Include custom exception classes for Array
#include "NumericArray.hpp"        // Include numeric array class
#include "PointArray.hpp"          // include PointArray class
#include "Stack.hpp"               // include Stack class
#include "StackException.hpp"      // include StackException class

#include <iostream>                // For std::cout and std::endl


int main()
{   
    // ===============================
    // Test Stack with Integer
    // ===============================

    Stack<int> stack1(3);

    try
    {
        std::cout << "Pushing elements: 2, 3, 4" << std::endl;                            // push elements
        stack1.Push(2);                                                                   // push value 2
        stack1.Push(3);                                                                   // push value 3
        stack1.Push(4);                                                                   // push value 4

        std::cout << "Popped Value: " << stack1.Pop() << std::endl;                       // pop three times
        std::cout << "Popped Value: " << stack1.Pop() << std::endl;
        std::cout << "Popped Value: " << stack1.Pop() << std::endl;

        // This should throw an exception
        std::cout << "Attempting to Pop from an empty stack..." << std::endl;             // force a pop error
        stack1.Pop();
    }
    catch(const StackEmptyException& e)
    {
        std::cout << "Exception: " << e.GetMessage() << std::endl;                        // exception occurs
    }

    try
    {
        std::cout << "Attempting to overfill the stack..." << std::endl;                  // try to overfill a stack
        stack1.Push(5);                                                                   // push value 5
        stack1.Push(6);                                                                   // push value 6
        stack1.Push(7);                                                                   // push value 7
        stack1.Push(8); // This should throw an overflow exception
    }
    catch(const StackFullException& e)
    {
        std::cout << "Exception: " << e.GetMessage() << std::endl;                        // throw an overflow exception
    }
    
    
    return 0; // Indicates a successfully ran program

}
