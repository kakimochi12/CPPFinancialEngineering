// Author: Kaiki Ikeda
// File: Exercise_2
// This program allows the user to input the coordinates of two 2D points.
// It then creates Point objects, calculates the distance of each point from the origin,
// and computes the distance between the two points using the Point class's member functions.

// main.cpp - Test program for the Point class

#include "Point.hpp"    // Include the Point class definition
#include <iostream>     // For input/output using std::cin and std::cout

int main()
{
    // Declare variables to store user input for the two points
    double x_one, y_one;
    double x_two, y_two;

    // Prompt the user for the first point's coordinates
    std::cout << "Enter a variable for the first x coordinate: ";
    std::cin >> x_one;

    std::cout << "Enter a variable for the first y coordinate: ";
    std::cin >> y_one;

    // Prompt the user for the second point's coordinates
    std::cout << "Enter a variable for the second x coordinate: ";
    std::cin >> x_two;

    std::cout << "Enter a variable for the second y coordinate: ";
    std::cin >> y_two;

    // Create two Point objects
    Point p_one;
    Point p_two;

    // Set their coordinates using setter functions
    p_one.SetX(x_one);
    p_one.SetY(y_one);

    p_two.SetX(x_two);
    p_two.SetY(y_two);

    // Output the distance from each point to the origin
    std::cout << "The distance between the origin and the FIRST point is: "
              << p_one.DistanceOrigin() << std::endl;

    std::cout << "The distance between the origin and the SECOND point is: "
              << p_two.DistanceOrigin() << std::endl;

    // Output the distance between the two points
    std::cout << "The distance between the first point and the second point is: "
              << p_one.Distance(p_two) << std::endl;

    return 0; // Indicate successful program termination
}
