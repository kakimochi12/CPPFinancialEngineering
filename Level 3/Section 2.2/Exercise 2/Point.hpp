// Point.hpp - Declaration of the Point class

#ifndef POINT_HPP
#define POINT_HPP

#include <string> // Required for std::string used in ToString()

// The Point class represents a 2D point with x and y coordinates
class Point
{
private:
    // x and y coordinate values (initialized to 0.0)
    double m_x = 0.0;
    double m_y = 0.0;

public:
    // Default constructor
    Point();

    // Destructor
    ~Point();

    // Getter for the x-coordinate
    double GetX();

    // Getter for the y-coordinate
    double GetY();

    // Setter for the x-coordinate
    void SetX(double number);

    // Setter for the y-coordinate
    void SetY(double number);

    // Returns a string representation of the point in the format: Point(x, y)
    std::string ToString();

    // Distance functions

    // Calculates the distance from this point to the origin (0, 0)
    double DistanceOrigin();

    // Calculates the distance from this point to another point
    double Distance(Point p);
};

#endif // POINT_HPP
