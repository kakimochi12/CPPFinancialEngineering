// Author: Kaiki Ikeda
// File: Exercise_1
// This program we added operators to our Line classes along with assignment operators for Line and circle class to avoid any complications with
// the canonical header file. Our main program aims to test these new operators out and see how they work!

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>

int main()
{
    // Testing negation operator
    Point p1(3.0, 4.0);
    Point p2 = -p1;
    std::cout << "This is the point after negation: " << p2.ToString() << std::endl;

    // Testing Scale operator
    p1 = p1 * 2.0;
    std::cout << "This is our scaled point: " << p1.ToString() << std::endl;

    // Testing addition operator
    p1 = p1 + p2;
    std::cout << "This is our added Point: " << p1.ToString() << std::endl;

    // Testing comparison operator
    Point p3(1.0, 1.0);
    Point p4(1.0, 1.0);

    std::cout << "(True) comparison: " << (p3 == p4) << std::endl;
    std::cout << "(False) comparison: " << (p1 == p2) << std::endl;

    // Test assignment operator
    p1 = p3;
    std::cout << "This should return coords (1, 1): " << p1.ToString() << std::endl;

    // Test scaling coords and assign operator
    p1 *= 4.0;
    std::cout << "This should be scaled to (4, 4): " << p1.ToString() << std::endl;

    // Test assignment for Line
    Line l1(Point(1.0, 1.0), Point(2.0, 2.0));
    Line l2(Point(9.0, 9.0), Point(3.0, 3.0));
    l1 = l2;
    std::cout << "Line one should be showing contents of line two: " << l1.ToString() << std::endl;

    // Test assignment for Circle
    Circle c1(Point(0.0, 0.0), 3);
    Circle c2(Point(9.0, 9.0), 10);

    c1 = c2;
    std::cout << "Circle one should be showing contents of Circle two: " << c1.ToString() << std::endl;

    return 0;
}