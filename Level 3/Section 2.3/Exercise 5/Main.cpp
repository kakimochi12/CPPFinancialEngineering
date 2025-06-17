// Author: Kaiki Ikeda
// File: Exercise_5
//
// This program tests the functionality of the newly created Line class, which is composed of two Point objects.
// It verifies correct implementation of all member functions including constructors (default, parameterized, and copy),
// getters and setters for the start and end points, the Length() function for calculating distance between the points,
// and the ToString() function for generating a descriptive string representation of the line.
// 
// The program also tracks the object lifecycle by observing when constructors and destructors are triggered.
// It builds on concepts from previous exercises such as const correctness, class composition, and object-oriented design.
//

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
    // Creating a line using the default constructor
    Line line1;
    std::cout << "Default Line:" << line1.ToString() << std::endl;

    // testing out our parameterized constructor
    Point point_one(3.0, 3.0);
    Point point_two(8.0, 1.0);
    Line line2(point_one, point_two);
    std::cout << "Our parameterized constructor outputs this: " << line2.ToString() << std::endl;

    // copy constructor test
    Line line3 = line2;
    std::cout << "This is a copied Line: " << line3.ToString() << std::endl;

    // Here we will test our getters Start() and End()
    std::cout << "Starting point of l2: " << line2.Start().ToString() << std::endl;
    std::cout << "Ending point of l1: " << line2.End().ToString() << std::endl;

    // Testing our setters now
    Point point_three(4.0, 2.0);
    line2.Start(point_three);
    line2.End(point_two);
    std::cout << "Updated Line2 points: " << line2.ToString() << std::endl;

    // test our length calculation
    std::cout << "Length of the line is: " << line2.Length() << std::endl;

    return 0;
}
