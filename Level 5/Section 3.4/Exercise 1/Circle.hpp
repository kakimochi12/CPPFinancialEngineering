// This is the header file for CIRCLE class we will be initializing


#ifndef CIRCLE_HPP // define circle header if not defined
#define CIRCLE_HPP // define circle header
#include "Point.hpp" // include some traits we have from Point class


// Class circle initialized
class Circle
{
private:

    Point m_center; // private members.. Center
    double m_radius; // private member .. radius

public:
    Circle(); // constructor
    Circle(const Point &center, const double radius); // parameterized constructor
    Circle(const Circle &other); // copy constructor
    ~Circle(); // destructor
    Point CentrePoint() const; // to return center
    double Radius() const; // returns radius
    double Diameter() const; // calculate Diameter
    double Area() const; // calculate Area
    double Circumference() const; // calculate circumference
    std::string ToString() const; // print out the contents of the circle

    void CentrePoint(const Point &center); // parameterized center point
    void Radius(const double radius); // parameterized radius

    // Assignment operator
    Circle& operator = (const Circle &source);
};


#endif