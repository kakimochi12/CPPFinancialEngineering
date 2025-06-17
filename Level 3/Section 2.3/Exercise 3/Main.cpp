// Author: Kaiki Ikeda
// File: Exercise_3
// This program demonstrates function overloading by using a unified interface for getters and setters,
// and calculates distances from the origin and between two points using overloaded Distance() methods.

#include "Point.hpp"   // Include the definition of the Point class
#include <iostream>    // Include input/output stream for console printing

int main()
{
    Point p1;  // Create first Point object using default constructor
    Point p2;  // Create second Point object using default constructor

    p1.X(4.0);  // Set x-coordinate of p1 to 4.0 using setter overload
    p1.Y(2.0);  // Set y-coordinate of p1 to 2.0 using setter overload

    p2.X(5.0);   // Set x-coordinate of p2 to 5.0 using setter overload
    p2.Y(1.0);    // Set y-coordinate of p2 to 1.0 using setter overload

    std::cout << "p1 X: " << p1.X() << ", Y: " << p1.Y() << std::endl;  // Get and print x and y of p1
    std::cout << "p2 X: " << p2.X() << ", Y: " << p2.Y() << std::endl;  // Get and print x and y of p2

    double distance1 = p1.Distance();   // Calculate distance from p1 to origin
    double distance2 = p2.Distance();   // Calculate distance from p2 to origin

    std::cout << "Distance to origin for p1: " << distance1 << std::endl;  // Print distance for p1
    std::cout << "Distance to origin for p2: " << distance2 << std::endl;  // Print distance for p2

    double distance_from_eachother = p1.Distance(p2);  // Calculate distance between p1 and p2

    std::cout << "The distance from each other is: " << distance_from_eachother << std::endl;  // Print result

    return 0;  // Indicate successful program termination
}
