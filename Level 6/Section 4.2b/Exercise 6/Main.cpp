// Author: Kaiki Ikeda
// File: Exercise_6
// In this program we create value template arguments for our stack where the template includes <typename T, int size>
// where size can be used to create an array of that size. We took down our size constructor due to this implementation.
// The main program tests this implementation and explore how Stacks of the same size can be assigned but not when they are different sizes.

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
    // create a stack of integers with size 3
    Stack<int, 3> stack1;
    // push some elements into the stack
    stack1.Push(10);
    stack1.Push(20);
    stack1.Push(30);

    // assignment
    Stack<int, 3> copy;
    copy = stack1;

    // it returns 30 because it copied stack1
    std::cout << "Testing Pop for copy: " << copy.Pop() << std::endl;

    
    // Stack<int, 5> error = stack1;
    // This doesnt work as only stacks with the same size template argument can be copied/assigned
    
    
    return 0; // Indicates a successfully ran program

}
