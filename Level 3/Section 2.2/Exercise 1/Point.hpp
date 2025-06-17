// Point.hpp - Class declaration for a 2D Point object

#ifndef POINT_HPP        // Prevent multiple inclusions of this header file
#define POINT_HPP

#include <string>       // Required for std::string used in ToString()

// Point class represents a 2D point with x and y coordinates
class Point
{
private:
    double m_x;         // X-coordinate (private member variable)
    double m_y;         // Y-coordinate (private member variable)

public:
    Point();     // Default constructor
    ~Point();    // Destructor

    double GetX();        // Getter function for x-coordinate
    double GetY();     // Getter function for y-coordinate

    void SetX(double x_number); // Setter function for x-coordinate
    void SetY(double y_number); // Setter function for y-coordinate

    std::string ToString();   // Returns a string representation of the point: "Point(x, y)"
};

#endif // POINT_HPP
