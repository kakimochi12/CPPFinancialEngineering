// Author: Kaiki Ikeda
// File: Exercise_2
// This program defines a Point class and demonstrates how constructors, a copy constructor,
// and a destructor behave when objects are created, passed by value or by const reference, and destroyed.
// It calculates the distance between two Point objects while tracking object lifecycle events using console output.


#include "Point.hpp"      // Include the Point class definition
#include <iostream>       // For std::cout and std::endl

int main()
{
    // Create the first Point using the coordinate constructor
    Point p1(4.0, 2.0);   // This will output: "Coordinate constructor was called!"

    // Create the second Point using the coordinate constructor
    Point p2(7.0, 2.0);   // This will output: "Coordinate constructor was called!"

    // Call the Distance function with p2 passed by const reference
    // Since it's passed by const reference, no copy constructor will be called
    double distance = p1.Distance(p2);

    // Print the calculated distance between the two points
    std::cout << "Distance: " << distance << std::endl;

    // When main() ends, both p1 and p2 go out of scope and their destructors will be called
    // Output: "Destructor was called!" (twice)
    
    return 0;
}
