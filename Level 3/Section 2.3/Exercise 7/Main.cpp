// Author: Kaiki Ikeda
// File: Exercise_7
// This file uses inline functions in the point.hpp file to learn how it can speed up execution of short functions because the code
// of such function will be copied then and there instead of calling.

#include "Point.hpp" // include header file
#include <iostream> // allow std::cout usage 

int main()
{
    Point p1(1.0, 2.0); // parameterized p1 initialization
    std::cout << "p1: " << p1.ToString() << std::endl; // print contents of p1

    p1.X(5.0); // set p1 X to 5.0
    p1.Y(7.0); // set p1 Y to 7.0
    std::cout << "After setting new values: " << p1.ToString() << std::endl; // print the new value contents

    std::cout << "p1 X: " << p1.X() << std::endl; // test the getter
    std::cout << "p1 Y: " << p1.Y() << std::endl; // test the getter

    return 0; // indicates a successfully ran program
}