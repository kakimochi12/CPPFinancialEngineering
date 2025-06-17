// Author: Kaiki Ikeda
// File: Exercise_1
// This program demonstrates runtime polymorphism by using a virtual function.
// When a Shape pointer points to a Point object, the overridden ToString()
// in Point should be invoked due to dynamic binding (not static binding).


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{
    Point p(1.0, 2.0); // initialize a point
    Shape *sp;         // initialize a shape pointer
    sp = &p;           // shape pointer POINTS to a point

    std::cout << "Test: " << sp->ToString() << std::endl;  // polymorphism (using virtual function) allows us to perform ToString of Point instead of base class function
    
    return 0; // indicates a successfully ran program
}

// The ToString() function of Point is called when you used a Shape* that comntains a Point