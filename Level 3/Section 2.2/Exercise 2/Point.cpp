// Point.cpp - Function implementations for the Point class

#include "Point.hpp"    // Include class declarations
#include <sstream>      // For std::stringstream used in ToString()
#include <string>       // For std::string
#include <cmath>        // For std::sqrt and std::pow (used in distance calculations)

// Default constructor - initializes x and y to 0.0
Point::Point()
{
    m_x = 0.0;
    m_y = 0.0;
}

// Destructor - no dynamic memory to release
Point::~Point()
{
    // No cleanup needed
}

// Getter for x-coordinate
double Point::GetX()
{
    return m_x;
}

// Getter for y-coordinate
double Point::GetY()
{
    return m_y;
}

// Setter for x-coordinate
void Point::SetX(double number)
{
    m_x = number;
}

// Setter for y-coordinate
void Point::SetY(double number)
{
    m_y = number;
}

// Returns a string representation of the point in the format: "Point(x, y)"
std::string Point::ToString()
{
    std::stringstream new_string;
    new_string << "Point(" << m_x << ", " << m_y << ")";
    return new_string.str();
}

// Calculates the distance from this point to the origin (0, 0)
double Point::DistanceOrigin()
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

// Calculates the distance from this point to another Point object
double Point::Distance(Point p)
{
    double distance_x = m_x - p.GetX();
    double distance_y = m_y - p.GetY();
    return std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
}
