// Author: Kaiki Ikeda
// File: Exercise_3
// This program aims to experiment with concrete inheritance. Originally we could create an array of points by directly insantiating the 
// Array class for the Point class, however, that doesnt allow us to add point's specific functionality so we use Array's template to make
// a specific case for Array filled with points and "customized" what it can do when it is so.

#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class definition 
#include "ArrayException.hpp"      // Include custom exception classes for Array
#include "NumericArray.hpp"        // Include numeric array
#include "PointArray.hpp"          // include PointArray

#include <iostream>                // For std::cout and std::endl

using namespace std;               // using directive for std::

int main()
{   
    // =============================
    // TEST FOR assignment operator
    // =============================
    PointArray points1(3);                                                            // initialize Array of points
    points1[0] = Point(1.0, 2.0);                                                     // assign first element
    points1[1] = Point(3.0, 4.0);                                                     // assign second element
    points1[2] = Point(5.0, 6.0);                                                     // assign third element

    PointArray points2(3);
    
    points2 = points1;                                                                // assignment operator exercised

    cout << "Testing assignment operator: " << points2.GetElement(1) << endl;         // output what points2's second element is

    // ================================
    // TEST FOR length function
    // ================================

    cout << "Test our length function: " << points1.Length() << endl;                 // output the length of contiguous array elements

    return 0; // Indicates a successfully ran program
}
