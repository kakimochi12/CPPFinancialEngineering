// Author: Kaiki Ikeda
// File: Exercise_1
// This program experiments using CAD and Container namespace to place specific classes under a certain category. We practice accessing 
// these classes via their new namespaces so we can see how developers use this to avoid global naming conflicts

#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>

using Kaiki::CAD::Line; // single namespace declaration for Line
using namespace Kaiki::Containers; // Complete namespace for all in containers
namespace alias = Kaiki::CAD; // giving our namespace a shorter alias

int main()
{
    Kaiki::CAD::Point p1(1.0, 2.0); // This creates a Point using the full namespace for Point class

    Line l1(p1, Kaiki::CAD::Point(2.0, 3.0)); // Testing Line constructor now that we used using declaration for single class
    std::cout << "This is the line: " << l1.ToString() << std::endl; 

    Array arr; // initializing an array using declaration for a complete namespace from Containers
    std::cout << "This is the size of the array: " << arr.Size() << std::endl;

    alias::Circle c1; // initializing a cricle using the shorter alias we designated at the top
    std::cout << "Center of the circle: " << c1.CentrePoint() << std::endl;

    return 0;
}