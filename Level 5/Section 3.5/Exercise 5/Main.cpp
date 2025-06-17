// Author: Kaiki Ikeda
// File: Exercise_5
// In this program we created a function for the base class as Print() that does all the functionality common to derived classes.
// The ToString function is different for each derived class but the template method pattern allows all the derived classes to use the Print()
// function only defined in our base class


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{
    Shape *shape_one;                // shape pointer initialized
    Shape *shape_two;                // shape pointer initialized
    
    Point p(1.0, 2.0);               // Point initialized
    Line l(p, Point(4.0, 5.0));      // Line initialized

    shape_one = &p;                  // Shape pointer points to Point
    shape_two = &l;                  // shape pointer points to line

    shape_one->Print();                 // use our Template method patterm and call Print()

    shape_two->Print();                 // using the method pattern again to call Print()


    return 0; // indicates a successfully ran program
}