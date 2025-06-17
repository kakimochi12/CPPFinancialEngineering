// Author: Kaiki Ikeda
// File: Exercise_3
// I created a type def for ShapeType variant which uses a function CreateShape and creates
// the shape that the user wants. We assign the variant to a line variable using boost::get function.
// We also use a visitor as the parent class to create operator() for each of our shapes. The ShapeMover
// shifts the point of our created shape.

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
#include "ShapeMover.hpp"          // include ShapeMover class


#include <iostream>                // For std::cout and std::endl

#include <boost/variant.hpp>

typedef boost::variant<Point, Line, Circle> ShapeType;      // defining our variant of potential types: Point, Line, Circle

// defining our CreateShape function
ShapeType CreateShape()
{
    int choice;                                                                 // store variable for user input
    std::cout << "Enter a number 1-3 to declare shape: " << std::endl;          // prompt user for a number
    std::cin >> choice;                                                         // store answer in choice


    // if input is 1, we create a Point
    if (choice == 1)                       
    {
        return Point(1.0, 2.0);
    }

    // if input is 2, we create a Line
    else if (choice == 2)
    {
        return Line(Point(1.0, 2.0), Point(2.0, 3.0));
    }

    // if input is 3, we create a Circle
    else if (choice == 3)
    {
        return Circle(Point(1.0, 2.0), 5);
    }

    // if number is out of range, we create a Point by default
    else
    {
        std::cout << "This is an invalid number! Returning default Point" << std::endl;
        return Point();
    }

}

int main()
{
    ShapeType myShape = CreateShape();                                          // perform CreateShape() function which asks the user what Shape to create
    std::cout << "Initial Shape: " << myShape << std::endl;                     // show contents of the shape


    // Check if we can extract a Line from the variant
    try
    {
        Line l = boost::get<Line>(myShape);                                     // Get a line from myShape
        std::cout << "This is the extracted Line: " << l << std::endl;          // show the contents of the Line
    }   
    catch(boost::bad_get &e)                                                    // if it captures an error from the previous line..
    {
        std::cerr << "Variant does not contain a line: " << e.what() << '\n';   // output an error
    }

    // Move the shape
    ShapeMover mover(5.0, 5.0);                 // initialize the amount we want to shift a shape                        
    boost::apply_visitor(mover, myShape);       // apply our class effect onto Shape

    std::cout << "Shape after shifting it: " << myShape << std::endl;

    return 0;  // indicates a successfully ran program
}