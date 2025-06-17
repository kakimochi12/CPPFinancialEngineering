#include "Point.hpp"      // Include the header file with the Point class definition
#include <iostream>       // For optional debugging/output
#include <cmath>          // For std::sqrt and std::pow

// Default constructor: initializes the point to (0.0, 0.0)
Point::Point()
{
    m_x = 0.0;
    m_y = 0.0;
}

// Destructor: no dynamic memory used, so nothing to clean up
Point::~Point()
{
}

// Getter for x-coordinate (does not modify the object)
double Point::X() const
{
    return m_x;
}

// Setter for x-coordinate
void Point::X(double number)
{
    m_x = number;
}

// Getter for y-coordinate (does not modify the object)
double Point::Y() const
{
    return m_y;
}

// Setter for y-coordinate
void Point::Y(double number)
{
    m_y = number;
}

// Calculates the distance from this point to the origin (0,0)
double Point::Distance() const
{
    return std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2));
}

// Calculates the distance between this point and another point
double Point::Distance(const Point &p) const
{
    double distance_x = m_x - p.m_x;
    double distance_y = m_y - p.m_y;

    return std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
}
