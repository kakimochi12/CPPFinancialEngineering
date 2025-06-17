#ifndef POINT_HPP             // Header guard to prevent multiple inclusions
#define POINT_HPP

// Definition of the Point class
class Point
{
private:
    double m_x = 0.0;     // X coordinate of the point, initialized to 0.0
    double m_y = 0.0;    // Y coordinate of the point, initialized to 0.0

public:
    Point();      // Default constructor creates a point at (0.0, 0.0)
    Point(double number_one, double number_two);  // Constructor with two values to initialize the point
    Point(const Point &other);   // Copy constructor creates a new Point as a copy of an existing one
    ~Point();                 // Destructor — called when a Point object is destroyed
    double Distance(const Point &p);  // Calculates the distance to another point (passed by const reference)
};

#endif        // End of header guard
