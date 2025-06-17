// Author: Kaiki Ikeda
// File: Exercise_1
// This file uses the Point class to create a 2D point object,
// set its coordinates based on user input, and display its values.

// Test program to demonstrate usage of the Point class

#include <iostream>     // For std::cin and std::cout
#include "Point.hpp"    // Include the Point class definition

int main()
{
    double x, y;  // Variables to store user input for coordinates

    // Prompt the user to enter the x-coordinate
    std::cout << "Enter a variable for x: ";
    std::cin >> x;

    // Prompt the user to enter the y-coordinate
    std::cout << "Enter a variable for y: ";
    std::cin >> y;

    // Create a Point object using the default constructor
    Point new_point;

    // Set the x and y coordinates of the Point using the setter functions
    new_point.SetX(x);
    new_point.SetY(y);

    // Output the string representation of the Point
    std::cout << new_point.ToString() << std::endl;

    // Output the individual x and y values using getter functions
    std::cout << "X: " << new_point.GetX() << ", Y: " << new_point.GetY() << std::endl;

    return 0;  // Indicate that the program ended successfully
}
