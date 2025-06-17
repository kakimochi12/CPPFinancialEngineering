// Author: Kaiki Ikeda
// File: Exercise_2
//  This exercise demonstrates calling base class functionality from derived classes.
//  We incorporated the Shape base class's ToString() method into the ToString() methods
//  of Point, Line, and Circle to include the unique shape ID in their output.


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{

    Shape *sh;                                                                 // initialize a shape pointer
    Point p(1.0, 2.0);                                                         // initialize a pointer
    sh = &p;                                                                   // shape pointer poitner to point
    std::cout << "This is a point test: " << sh->ToString() << std::endl;      // print ID and point information

    Shape *sh2;                                                                // initialize shape pointer
    Line l(Point(2.0, 3.0), p);                                                // initialize a Line
    sh2 = &l;                                                                  // shape pointer points to line
    std::cout << "This is a line test: " << sh2->ToString() << std::endl;      // print ID and Line information

    return 0; // indicates a successfully ran program
}

// ID is now printed when printing a point or line.