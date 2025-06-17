// cpp file to specfically instruct what each function will do

#define _USE_MATH_DEFINES // Enabling use of M_PI
#include <cmath> // In combination with the prior define so we can use m_pi
#include "Circle.hpp" // Including header file
#include <string> // for type string
#include <sstream> // build stream with std::stringstream
#include <iostream> // for basic input and output



// Circle constructor using colon syntax to assign a default center and radius value
Circle::Circle() : Shape(), m_center(Point(0, 0)), m_radius(0.0)
{
    
}

// Circle with immediate Center and Radius designation using colon syntax
Circle::Circle(const Point &center, const double radius) : Shape(), m_center(center), m_radius(radius)
{

}

// Copy constructor using colon syntax to copy center and radius
Circle::Circle(const Circle &other) : Shape(other), m_center(other.m_center), m_radius(other.m_radius)
{
    
}


// destructor
Circle::~Circle()
{
    // std::cout << "Circle Destructor Called!" << std::endl;
    // Destructor
}


// Return the centre point
Point Circle::CentrePoint() const
{
    return m_center;
}


// returns a radius of type double
double Circle::Radius() const
{
    return m_radius;
}

// Function to calculate the diameter of a circle with its center and radius
double Circle::Diameter() const
{
    return 2 *  m_radius; // formula for diameter 2 times r
}

// function to calculate the area of a circle 
double Circle::Area() const
{
    return (M_PI) * std::pow(m_radius, 2); // Area formula pi r squared
}

// Calculate the circumference
double Circle::Circumference() const
{
    return 2 * M_PI * m_radius; // formula for circumference 2 pi r
}

// print out the contents of the circle using ToString method from base class and append the string to our return description
std::string Circle::ToString() const
{
    std::string s = Shape::ToString();
    return s + ": Circle with a center: " + m_center.ToString() + "and radius: " + std::to_string(m_radius);
}

// Immediate center designation
void Circle::CentrePoint(const Point &center)
{
    m_center = center;
}

// immediate radius designation
void Circle::Radius(const double radius)
{
    m_radius = radius;
}

// Assignment operator
Circle& Circle::operator = (const Circle &source)
{
    if (this == &source)                  // check if circle already equals source
    {
        return *this;                     // return current circle
    }

    Shape::operator = (source);           // copy the base class

    m_center = source.m_center;           // set new center
    m_radius = source.m_radius;           // set new radius
    return *this;                         // return new circle
}

std::ostream& operator << (std::ostream& os, const Circle &source)
{
    os << source.ToString();
    return os;
}

