#ifndef POINT_HPP    // Start of header guard to prevent multiple inclusions
#define POINT_HPP

// Declaration of the Point class
class Point
{
private:
    double m_x = 0.0;  // Private member variable: x-coordinate, default initialized to 0.0
    double m_y = 0.0;   // Private member variable: y-coordinate, default initialized to 0.0

public:
    Point();        // Default constructor: initializes m_x and m_y to 0.0
    ~Point();      // Destructor: cleans up the object (no dynamic memory here)

    double X() const;  // Getter for x-coordinate (marked const since it doesn't modify the object)
    void X(double number);   // Setter for x-coordinate

    double Y() const;  // Getter for y-coordinate (const-qualified)
    void Y(double number);   // Setter for y-coordinate

    double Distance() const;        // Calculates distance from the origin
    double Distance(const Point &p) const;       // Calculates distance to another point (passed by const reference)
};
#endif                        // End of header guard
