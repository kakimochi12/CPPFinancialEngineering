#include "Point.hpp"
#include <cmath>
#include <sstream>
#include <iostream>
#include <string>


// Default constructor using colon syntax
Point::Point() : Shape(), m_x(0.0), m_y(0.0)
{
    // std::cout << "Default constructor was called!" << std::endl;
}

// Constructor with coordinates using colon syntax
Point::Point(double x, double y) : Shape(), m_x(x), m_y(y)
{
    // std::cout << "Coordinate constructor was called!" << std::endl;
}

// Copy constructor using colon syntax
Point::Point(const Point& other) : Shape(other), m_x(other.m_x), m_y(other.m_y)
{
    // std::cout << "Copy constructor was called!" << std::endl;
}

// Destructor
Point::~Point()
{
    // std::cout << "Destructor was called!" << std::endl;
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

// Return a string representation of the point called the ToString() method of the shape base class and append it to the return description
std::string Point::ToString() const
{
    std::string s = Shape::ToString();

    return s + ": Point(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
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

// Negate coords
Point Point::operator-() const
{
    return Point(-m_x, -m_y);
}

// Scale coords
Point Point::operator * (double factor) const
{
    return Point(m_x * factor, m_y * factor);
}

// Add coords
Point Point::operator + (const Point &p) const
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

// Equally compare operator
bool Point::operator == (const Point &p) const
{
    return (m_x == p.m_x && m_y == p.m_y);
}

// Assignment operator
Point& Point::operator = (const Point &source)
{
    if (this == &source)
    {
        return *this;
    }

    Shape::operator = (source); // copies the base class part

    m_x = source.m_x;
    m_y = source.m_y;
    return *this;
}

// Scale coords and assign
Point& Point::operator *= (double factor)
{
    m_x *= factor;
    m_y *= factor;
    return *this;
}

// Ostream operator
std::ostream& operator << (std::ostream& os, const Point &p)
{
    os << p.ToString();
    return os;
}

// Draw function from our base class - Prints text to simulate drawing
void Point::Draw() const
{
    std::cout << "This is a drawing of a Point" << std::endl;
}


