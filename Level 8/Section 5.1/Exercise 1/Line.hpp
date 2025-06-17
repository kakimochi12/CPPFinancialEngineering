// Header file to initialize our class and functions

#ifndef LINE_HPP
#define LINE_HPP // Defining the LINE_HPP file

#include "Point.hpp" // We have to use the elements in the class Point to supplement our Line class
#include "Shape.hpp" // include our Shape base class
#include <string> // we want it for ToString()


class Line : public Shape // inheritance 
{
private:
    Point point_one; // initialize var for type Point (start point)
    Point point_two; // initialize different var for type point as well (end point)
public:
    Line(); // Constructor
    Line(const Point &start, const Point &end); // Constructor with parameters.. allows for immediate start and end point designation
    Line(const Line &other); // copy constructor
    ~Line(); // destructor
    Point Start() const; // Getter for the starting point
    Point End() const; // Getter for the end Point
    void Start(const Point &start); // this is our setter for starting point
    void End(const Point &end); // setter for ending point
    std::string ToString() const; // Expresses contents of our line in string format
    double Length() const; // Gives us the length of the Line

    // Assignment operator
    Line& operator = (const Line &source);

};

#endif // end for #IFNDEF