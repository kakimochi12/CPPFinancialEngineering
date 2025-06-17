// Author: Kaiki Ikeda
// File: Exercise_6
// This assignment we created a circle class that has a center point and a radius. We created a constructor, destructor, selector, and modifier functions.
// We also added functions for getting the diameter, area, and circumference where we will test in the Main.cpp file because it is good practice

#include "Circle.hpp" // so we can use our circle class
#include <iostream> // so we can std::cout

int main()
{
    // test circle initialization
    Circle c1;
    std::cout << "We made this circle: " << c1.ToString() << std::endl; 

    // Test parameterized constructor
    Circle c2(Point(3.0, 2.0), 2.0);
    std::cout << "Circle that we immediately initialized: " << c2.ToString() << std::endl;

    // Test copy constructor
    Circle c3 = c2;
    std::cout << "Copied circle: " << c3.ToString() << std::endl;

    // Test the calculations of diameter, area, and circumference
    std::cout << "This is the diameter: " << c2.Diameter() << std::endl;
    std::cout << "This is the area: " << c2.Area() << std::endl;
    std::cout << "This is the circumference: " << c2.Circumference() << std::endl;

    // Test the getter functions
    std::cout << "Testing the getter for center point: " << c2.CentrePoint().ToString() << std::endl;
    std::cout << "Testing the getter for radius: " << c2.Radius() << std::endl;

    // Test the setter functions
    c2.CentrePoint(Point(7.0, 2.0));
    std::cout << "Testing the getter for ALTERED center point: " << c2.CentrePoint().ToString() << std::endl;
    c2.Radius(3.4);
    std::cout << "Testing the getter for ALTERED radius: " << c2.Radius() << std::endl;

    return 0; // indicates a successfully ran program

}