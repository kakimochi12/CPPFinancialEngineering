#include "Point.hpp"
#include <cmath>
#include <sstream>
#include <iostream>

// Default constructor
Point::Point() : m_x(0.0), m_y(0.0) 
{
    std::cout << "Default constructor was called!" << std::endl;
}

// Constructor with coordinates
Point::Point(double x, double y) : m_x(x), m_y(y) 
{
    std::cout << "Coordinate constructor was called!" << std::endl;
}

// Copy constructor
Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y) 
{
    std::cout << "Copy constructor was called!" << std::endl;
}

// Destructor
Point::~Point() 
{
    std::cout << "Destructor was called!" << std::endl;
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