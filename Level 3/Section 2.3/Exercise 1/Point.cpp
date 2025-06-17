#include "Point.hpp"          // Include the class declaration
#include <cmath>              // For mathematical functions like sqrt and pow
#include <iostream>           // For console output

// Default constructor
Point::Point()
{
    std::cout << "Constructor was called!" << std::endl;  // Message when default constructor is triggered
}

// Constructor with x and y coordinates
Point::Point(double number_one, double number_two)
{
    std::cout << "Coordinate constructor was called!" << std::endl;  // Message when coordinate constructor is triggered
    m_x = number_one;  // Initialize m_x with provided value
    m_y = number_two;  // Initialize m_y with provided value
}

// Copy constructor
Point::Point(const Point &other)
{
    std::cout << "Copy constructor was called!" << std::endl;  // Message when copy constructor is triggered
    m_x = other.m_x;  // Copy x-coordinate from another Point
    m_y = other.m_y;  // Copy y-coordinate from another Point
}

// Destructor
Point::~Point()
{
    std::cout << "Destructor was called!" << std::endl;  // Message when destructor is triggered
}

// Distance function that takes another Point by value (copies the point)
// This will intentionally trigger the copy constructor for the experiment
double Point::Distance(Point p)
{
    double distance_x = (m_x - p.m_x);  // Calculate difference in x
    double distance_y = (m_y - p.m_y);  // Calculate difference in y

    // Return the Euclidean distance between the two points
    return std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
}
