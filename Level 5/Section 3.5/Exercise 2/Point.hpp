#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include "Shape.hpp" // include our shape header file



class Point : public Shape // class Point creation inheriting shape
{
private:
    double m_x; // initialize double var
    double m_y; //initialize double var

public:
    // Constructors and Destructor
    Point();                          // Default constructor
    Point(double x, double y);         // Constructor with coordinates
    Point(const Point& other);         // Copy constructor
    ~Point();                          // Destructor

    // Combined Getter/Setter for x and y
    double X() const;                  // Getter FOR THE EXERCISE we have to set this const to let the program now when we call this on a const class, we will not be changing anything
    void X(double newX);               // Setter

    double Y() const;                  // Getter FOR THE EXERCISE we have to set this const to let the program now when we call this on a const class, we will not be changing anything
    void Y(double newY);               // Setter

    // Other member functions
    std::string ToString() const; // setting ToString function to const because it does not change the point object. We can avoid the compiler errors we learned in this lesson that way
    double Distance(const Point& p) const; // setting Distance to const because it does not change the point object. We can avoid the compiler errors we learned this way
    double Distance() const;

    // Adding operators to our Point class
    Point operator - () const;                  // Negate the coords
    Point operator * (double factor) const;     // scale the coords
    Point operator + (const Point &p) const;    // add coords
    bool operator == (const Point &p) const;   // equally compare Points
    Point& operator = (const Point &source);    // Set operator to new Point
    Point& operator *= (double factor);         // scale Point by factor and assign

};

// ostream operator allows for sending a point directly to the cout object without calling ToString method
std::ostream& operator << (std::ostream& os, const Point &p);


#endif
