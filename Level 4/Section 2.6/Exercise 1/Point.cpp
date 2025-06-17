#include "Point.hpp"
#include <cmath>
#include <sstream>
#include <iostream>

namespace Kaiki // putting our Line class into our namespace
{
namespace CAD // line will be a part of our Kaiki::CAD namespace
{

// Default constructor
Point::Point() : m_x(0.0), m_y(0.0) 
{
    //std::cout << "Default constructor was called!" << std::endl;
}

// Constructor with coordinates
Point::Point(double x, double y) : m_x(x), m_y(y) 
{
    //std::cout << "Coordinate constructor was called!" << std::endl;
}

// Copy constructor
Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y) 
{
    //std::cout << "Copy constructor was called!" << std::endl;
}

// Destructor
Point::~Point() 
{
    //std::cout << "Destructor was called!" << std::endl;
}

// Getter for x
double Point::X() const 
{
    return m_x;
}

// Setter for x
void Point::X(double newX) 
{
    m_x = newX;
}

// Getter for y
double Point::Y() const 
{
    return m_y;
}

// Setter for y
void Point::Y(double newY) 
{
    m_y = newY;
}

// Return a string representation of the point
std::string Point::ToString() const 
{
    std::stringstream ss;
    ss << "Point(" << m_x << ", " << m_y << ")";
    return ss.str();
}

// Calculate distance between this point and another
double Point::Distance(const Point& p) const 
{
    double distance_x = (m_x - p.m_x);
    double distance_y = (m_y - p.m_y);
    return std::sqrt(distance_x * distance_x + distance_y * distance_y);
}

// Calculate a point's distance to the origin
double Point::Distance() const 
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}




// negate coords
Point Point::operator-() const
{
    return Point(-m_x, -m_y);                          // return Point by initializing negative coords
}

// scale coords
Point Point::operator * (double factor) const
{
    return Point(m_x * factor, m_y * factor);          // return Point with m_x and m_y multiplied by factor
}

// add coords
Point Point::operator + (const Point &p) const
{
    return Point(m_x + p.m_x, m_y + p.m_y);            // return Point with m_x and m_y added by corresponding x and y of other Point
}

// equally compare operator
bool Point::operator == (const Point &p) const
{
    return (m_x == p.m_x && m_y == p.m_y);             // compare each of x and y. It will return True if both are True, else False
}

// Assignment operator
Point& Point::operator = (const Point &source)
{
    if (this == &source)                               // Check if this is already equal to source
    {
        return *this;                                  // return the current Point
    }

    m_x = source.m_x;                                  // set m_x to the other Point's x coord
    m_y = source.m_y;                                  // set m_y to the other Point's y coord
    return *this;                                      // return this Point
}

// scale the coords and assign
Point& Point::operator *= (double factor)
{
    m_x *= factor;                  // scale m_x by factor
    m_y *= factor;                  // scale m_y by factor

    return *this;                   // return our point after being scaled
}

// ostream operator, prints contents of Point
std::ostream& operator << (std::ostream& os, const Point &p)
{
    os << p.ToString();
    return os;
}

} // namespace CAD
} // namespace Kaiki