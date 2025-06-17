// Author: Kaiki Ikeda
// File: Exercise_3
// This program demonstrates proper use of destructors in a class hierarchy involving inheritance. 
// It shows how destructors in derived classes such as Point and Line are invoked when objects 
// are deleted through base class (Shape) pointers. The program also highlights the importance of 
// declaring destructors as virtual in the base class to ensure that the correct destructor sequence 
// is executed for derived class objects during deletion.


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{
    Shape* shapes[3]; 
    shapes[0]=new Shape; 
    shapes[1]=new Point; 
    shapes[2]=new Line; 
    for (int i=0; i!=3; i++) delete shapes[i];

    // from the first test run before we declared virtual, only the base class Shape destructor was called, even for obkects that were
    // actually Point and Line. The compiler used static binding and never checked the actual type of the object

    // declaring in our base class virtual ~Shape() enables dynamic dispatch, so when delete it called on Shape* pointing to a derived object,
    // both the derived and base destructors will run in the correct order
    

    return 0; // indicates a successfully ran program
}

