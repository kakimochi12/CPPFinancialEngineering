#include "Point.hpp"          // Include the Point class definition
#include <cmath>              // For std::sqrt and std::pow
#include <iostream>           // For std::cout and std::endl

// Default constructor
Point::Point()
{
    std::cout << "Constructor was called!" << std::endl;  // Message printed when default constructor is used
}

// Constructor with two parameters for x and y
Point::Point(double number_one, double number_two)
{
    std::cout << "Coordinate constructor was called!" << std::endl;  // Message when coordinate constructor is used
    m_x = number_one;  // Set x-coordinate
    m_y = number_two;  // Set y-coordinate
}

// Copy constructor
Point::Point(const Point &other)
{
    std::cout << "Copy constructor was called!" << std::endl;  // Message when a copy is made
    m_x = other.m_x;  // Copy x from other point
    m_y = other.m_y;  // Copy y from other point
}

// Destructor
Point::~Point()
{
    std::cout << "Destructor was called!" << std::endl;  // Message printed when object is destroyed
}

// Distance function that calculates the distance from this point to another point
// Takes the input point by const reference to avoid copying and protect against modification
double Point::Distance(const Point &p)
{
    // p.m_x = 10.0;  // Uncommenting this would cause a compile error, since p is const

    double distance_x = (m_x - p.m_x);  // Difference in x-coordinates
    double distance_y = (m_y - p.m_y);  // Difference in y-coordinates

    // Return Euclidean distance between the two points
    return std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
}
