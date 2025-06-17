// Function implementations for the Point class

#include "Point.hpp"     // Include class declarations
#include <string>        // Required for std::string (used in ToString)
#include <sstream>       // Required for std::stringstream (used to build the string)

// Default constructor - initializes x and y to 0
Point::Point()
{
    m_x = 0.0;
    m_y = 0.0;
}

// Destructor - nothing to clean up (no dynamic memory)
Point::~Point()
{
    // No resources to free
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

// Returns a string representation of the point in the format: Point(x, y)
std::string Point::ToString()
{
    std::stringstream convert_string;
    convert_string << "Point(" << m_x << ", " << m_y << ")";
    return convert_string.str();
}
