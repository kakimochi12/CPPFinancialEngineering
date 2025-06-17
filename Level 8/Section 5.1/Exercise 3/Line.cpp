// This is where we designate what the functions we defined in the header file do

#include "Line.hpp"  // we need to include Line.hpp because we want to use the elements of this function
#include "Point.hpp" // need to include Point as well. we are using traits from both and they are connected
#include <iostream> // for simple std::cout


Line::Line() : Shape(), point_one(Point(0.0, 0.0)), point_two(Point(0.0, 0.0)) // default constructor using colon syntax to initialize point at origin and second point at origin as well
{
    
} 

Line::Line(const Point &start, const Point &end) : Shape(), point_one(start), point_two(end) // parameterized constructor using colon syntax to set starting and ending variables
{
    
}

Line::Line(const Line &other) : Shape(other), point_one(other.point_one), point_two(other.point_two) // Copy constructor using colon syntax to set point one and two to our copy values
{
    //std::cout << "Line copy contructor called!" << std::endl; // lets the user see that Line was copied

}

Line::~Line()
{
    // std::cout << "Line Destructor Called!" << std::endl;
    // destructor.. leave blank
}

Point Line::Start() const // getter for the starting point
{
    return point_one;
}

Point Line::End() const // getter for our ending point
{
    return point_two;
}

void Line::Start(const Point &start) // setter for our starting point
{
    point_one = start;
}

void Line::End(const Point &end) // setter for ending point
{
    point_two = end;
}

std::string Line::ToString() const // Expresses line contents into string format. Called ToString method from base class Shape and appended it to our return description
{
    std::string s = Shape::ToString();
    return s + ": Line from " + point_one.ToString() + " to " + point_two.ToString(); // concatenation technique for strings
}

double Line::Length() const // return the length of the line using delegation
{
    return point_one.Distance(point_two);
}

// Assignment operator
Line& Line::operator = (const Line &source)
{
    if (this == &source)                // check if current is equal to source
    {
        return *this;                   // return the line
    }

    Shape::operator = (source);         // copy base class part

    point_one = source.point_one;       // assign first point
    point_two = source.point_two;       // assign second point
    return *this;                       // return the new line
}

// << operator
std::ostream& operator << (std::ostream &os, const Line &source)
{
    os << source.ToString();
    return os;
}




