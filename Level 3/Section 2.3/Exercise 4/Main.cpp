// Author: Kaiki Ikeda
// File: Exercise_4
// In this program we did a continuation of exercise 3 but this time, we saw how intializing a const object does not allow us to use normal getter and setter functions
// C++ program wants us to explicity specify const functions so that it knows we won't change anything.


#include "Point.hpp"      // Include the Point class definition
#include <iostream>       // For std::cout and std::endl

int main()
{
    // This code right here is part 1 of the assignment for exercise 4. There is a compiler error because we are trying to set the value 0.3
    // when the object we created is a const, meaning it's values DO NOT change.
    //
    // 
    //       const Point cp(1.5, 3.9);
    //       cp.X(0.3);

    const Point cp(1.5, 3.9); // create an unchangeable Point cp object
    std::cout << cp.X() << std::endl; // This didnt work when we didnt have const at the end of our getter for x function 
    std::cout << cp.Y() << std::endl; // Showing the success of cp.Y() after we added const

    double distance = cp.Distance(); // variable to hold the distance variabe
    std::cout << "Distance from origin: " << distance << std::endl; // print out the distance

    std::cout << "This is what the ToString function brings us: " << cp.ToString() << std::endl; // print out the ToString result

    return 0;
}
