// This is where we designate what the functions we defined in the header file do

#include "Line.hpp"  // we need to include Line.hpp because we want to use the elements of this function
#include "Point.hpp" // need to include Point as well. we are using traits from both and they are connected
#include <iostream> // for simple std::cout

Line::Line() // default constructor
{
    point_one = Point(0.0, 0.0); // Initializes a point at the origin
    point_two = Point(0.0, 0.0); // initialize a second point also at the origin
} 

Line::Line(const Point &start, const Point &end) // parameterized constructor
{
    point_one = start; // set starting to first variable passed in
    point_two = end; // set ending to second variable passed in
}

Line::Line(const Line &other) // Copy constructor
{
    //std::cout << "Line copy contructor called!" << std::endl; // lets the user see that Line was copied
    point_one = other.point_one; // behind the scenes setting point_one and point_two to our copy values
    point_two = other.point_two;
}

Line::~Line()
{
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

std::string Line::ToString() const // Expresses line contents into string format
{
    return "Line from " + point_one.ToString() + " to " + point_two.ToString(); // concatenation technique for strings
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

    point_one = source.point_one;       // assign first point
    point_two = source.point_two;       // assign second point
    return *this;                       // return the new line
}



