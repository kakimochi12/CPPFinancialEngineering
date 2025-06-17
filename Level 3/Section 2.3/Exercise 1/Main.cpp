// Author: Kaiki Ikeda
// File: Exercise_1
// This program defines a Point class and demonstrates the use of constructors, a copy constructor, and a destructor.
// It calculates the distance between two points while tracking object creation and destruction through console output.


#include "Point.hpp"      // Include the Point class definition
#include <iostream>       // For console output (std::cout)

int main()
{
    // Create the first Point using the coordinate constructor
    Point p1(3.0, 4.0);  // Outputs: "Coordinate constructor was called!"

    // Create the second Point using the coordinate constructor
    Point p2(1.0, 2.0);  // Outputs: "Coordinate constructor was called!"

    // Call the Distance function — p2 is passed by value, so a copy is made
    // This will trigger the copy constructor and eventually a destructor
    double result = p1.Distance(p2);  // Outputs: "Copy constructor was called!" and "Deconstructor was called!"

    // Print the calculated distance between p1 and p2
    std::cout << "Distance: " << result << std::endl;

    // When main ends, p2 and p1 go out of scope and their destructors are called
    // Outputs: "Deconstructor was called!" (for p2 and p1)
    
    return 0;
}
