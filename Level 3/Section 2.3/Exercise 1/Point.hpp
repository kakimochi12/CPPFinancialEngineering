#ifndef POINT_HPP            // Header guard: prevents this file from being included multiple times
#define POINT_HPP

class Point                // Define the Point class
{
private:       // Private section: variables only accessible from inside the class
    double m_x = 0.0;     // X-coordinate of the point, default initialized to 0.0
    double m_y = 0.0;     // Y-coordinate of the point, default initialized to 0.0

public:           // Public section: functions accessible from outside the class
    Point();       // Default constructor (no arguments) — initializes to (0, 0) and prints a message

    Point(double number_one, double number_two);  
    // Constructor that takes x and y values directly — used to initialize the point with specific values
    // Also prints a message to track constructor calls

    Point(const Point &other);  
    // Copy constructor — creates a new Point by copying another Point
    // Prints a message so you can track when copying happens

    ~Point();             
    // Destructor — called automatically when a Point object is destroyed
    // Prints a message to help count destructors during the experiment

    double Distance(Point p);  
    // Member function to calculate the distance between this point and another point (passed **by value**)
    // Since it's passed by value, the copy constructor will be triggered
};

#endif                    // End of the header guard
