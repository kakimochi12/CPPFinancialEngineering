// cpp file to specfically instruct what each function will do

#define _USE_MATH_DEFINES // Enabling use of M_PI
#include <cmath> // In combination with the prio define so we can use m_pi
#include "Circle.hpp" // Including header file
#include <string> // for type string
#include <sstream> // build stream with std::stringstream

// Circle constructor
Circle::Circle()
{
    m_center = Point(0, 0); // set a center
    m_radius = 0.0; // set a radius
}

// Circle with immediate Center and Radius designation
Circle::Circle(const Point &center, const double radius)
{
    m_center = center; // Set center with passed in center
    m_radius = radius; // set Radius with passed in radius
}

// Copy constructor
Circle::Circle(const Circle &other)
{
    m_center = other.m_center; // Set center to copy center
    m_radius = other.m_radius; // set radius to copy radius
}


// destructor
Circle::~Circle()
{
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

// print out the contents of the circle
std::string Circle::ToString() const
{
    std::stringstream ss;
    ss << "Circle with a center: " << m_center.ToString() << "and radius: " << m_radius; // create string with Circle contents
    return ss.str(); // build the stream as a string
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

