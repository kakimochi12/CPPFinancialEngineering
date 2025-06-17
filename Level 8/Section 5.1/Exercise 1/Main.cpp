// Author: Kaiki Ikeda
// File: Exercise_1
// In this exercise, we observed how smart pointers are automatically managed from construction to destruction.
// We used the Boost library to create shared pointers for our Shape class and store them in an array.
// Without manually freeing memory after the program finishes, Boost's shared_ptr takes care of the cleanup for us.


#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class definition 
#include "ArrayException.hpp"      // Include custom exception classes for Array
#include "NumericArray.hpp"        // Include numeric array class
#include "PointArray.hpp"          // include PointArray class
#include "Stack.hpp"               // include Stack class
#include "StackException.hpp"      // include StackException class
#include "Circle.hpp"              // include Circle class
#include "Shape.hpp"               // include Shape class
#include "Line.hpp"                // include Line class


#include <iostream>                // For std::cout and std::endl

#include <boost/smart_ptr.hpp>    // include shared_ptr feature

using namespace std;               // declare namespace std

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{   
    // inititalize ShapeArray of shared pointers for Shape 
    ShapeArray shape(3);


    // Filling the array up with Shapes
    shape[0] = ShapePtr(new Point(1.0, 2.0));
    shape[1] = ShapePtr(new Circle(Point(0, 0), 5.0));
    shape[2] = ShapePtr(new Line(Point(2.0, 2.0), Point(5.0, 6.0)));


    // Loop through the array to print each element
    for (int i = 0; i < shape.Size(); ++i)
    {
        cout << "Printing Shape: " << shape[i]->ToString() << endl;
    }

    return 0; // Indicates a successfully ran program
}
