// Author: Kaiki Ikeda
// File: Exercise_1
// In this program, we addressed the limitation of the original Array class, which was tightly coupled with Point objects.
// By leveraging generic programming concepts, we introduced a Template <T>, allowing the Array to store any data type.
// This transformation enhanced the flexibility and reusability of the Array class, enabling it to manage
// not only Points but also other Abstract Data Types (ADTs) like integers, doubles, or even custom objects.

#include "Point.hpp"               // Include Point class definition
#include "Array.cpp"               // Include Array class definition THIS TIME using source file for template
#include "ArrayException.hpp"      // Include custom exception classes for Array

#include <iostream>                // For std::cout and std::endl

using namespace std;               // using directive for std::

int main()
{
    Array<Point> point(3);                                        // creating an array of points with new template
    cout << "Test for Array template: " << point[0] << endl;      // printing the first element in the array


    return 0; // Indicates a successfully ran program
}
