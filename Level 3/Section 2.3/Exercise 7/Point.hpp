#ifndef POINT_HPP
#define POINT_HPP

#include <string>

class Point // class Point creation
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
    double X() const;                  
    void X(double newX) {m_x = newX;} // This is the default inline for the X setter in the class declaration               

    double Y() const;                  
    void Y(double newY) {m_y = newY;} // This is the default inline for the Y setter in the class declaration             

    // Other member functions
    std::string ToString() const; // setting ToString function to const because it does not change the point object. We can avoid the compiler errors we learned in this lesson that way
    double Distance(const Point& p) const; // setting Distance to const because it does not change the point object. We can avoid the compiler errors we learned this way
    double Distance() const;
};

// normal inline for the getter X OUTSIDE of the class declaration
inline double Point::X() const
{
    return m_x;
}

// normal inline for the getter Y OUTSIDE of the class declaration
inline double Point::Y() const
{
    return m_y;
}

#endif
