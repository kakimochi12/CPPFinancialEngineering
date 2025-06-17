// Author: Kaiki Ikeda
// File: Exercise_2
// This program aims to experiment our newly implemented ostream operator so that we can print the contents of our class without
// explicitly having to call ToString function.

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>

int main()
{
    // Testing negation operator
    Point p1(3.0, 4.0);
    Point p2 = -p1;
    std::cout << "This is the point after negation: " << p2 << std::endl;          // Ostream operator being tested

    // Testing Scale operator
    p1 = p1 * 2.0;
    std::cout << "This is our scaled point: " << p1 << std::endl;                  // Ostream operator being tested

    // Testing addition operator
    p1 = p1 + p2;
    std::cout << "This is our added Point: " << p1 << std::endl;                   // Ostream operator being tested

    // Testing comparison operator
    Point p3(1.0, 1.0);
    Point p4(1.0, 1.0);

    std::cout << "(True) comparison: " << (p3 == p4) << std::endl;
    std::cout << "(False) comparison: " << (p1 == p2) << std::endl;

    // Test assignment operator
    p1 = p3;
    std::cout << "This should return coords (1, 1): " << p1 << std::endl;          // Ostream operator being tested

    // Test scaling coords and assign operator
    p1 *= 4.0;
    std::cout << "This should be scaled to (4, 4): " << p1 << std::endl;           // Ostream operator being tested

    // Test assignment for Line
    Line l1(Point(1.0, 1.0), Point(2.0, 2.0));
    Line l2(Point(9.0, 9.0), Point(3.0, 3.0));
    l1 = l2;
    std::cout << "Line one should be showing contents of line two: " << l1 << std::endl;    // Ostream operator being tested

    // Test assignment for Circle
    Circle c1(Point(0.0, 0.0), 3);
    Circle c2(Point(9.0, 9.0), 10);

    c1 = c2;
    std::cout << "Circle one should be showing contents of Circle two: " << c1 << std::endl;    // Ostream operator being tested

    return 0;
}