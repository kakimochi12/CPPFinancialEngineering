// Author: Kaiki Ikeda
// File: Exercise_4
// This file aims to experiment with friends, we moved our std::ostream << operator inside the class function and declared it as a friend
// so that it can directly access the data members without having to call the ToString function.

#include "Point.hpp"
#include "Line.hpp"

#include <iostream>

int main()
{
    Point p1(3.0, 4.0);
    Point p2(2.0, 6.0);

    
    // Call my global operator << function for Point
    // Since it is now declared as friend inside the class
    // It accesses data members directly without calling ToString()
    std::cout << "Test our Point friend: " << p1 << std::endl;

    Line l1(p1, p2);

    // Call my global operator << function for Line
    // Since it is now declared as friend inside the class
    // It accesses data members directly without calling ToString()
    std::cout << "Test our Line friend: " << p2 << std::endl;

    return 0;

}