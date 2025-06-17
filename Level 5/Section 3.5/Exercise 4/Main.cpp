// Author: Kaiki Ikeda
// File: Exercise_4
//  In this program, we use polymorphism through an abstract base class `Shape`.
//  We create a `Shape*` array and fill it with `Point` and `Line` objects, using dynamic dispatch
//  with a virtual `Draw()` function. This demonstrates runtime polymorphism and proper memory management.


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{
    // Shape s; ---> here i tried to create an instance of the Shape class but it is not possible. We initialized a virtual Draw() function, making this class and abstract base class
    
    Shape *shapes[10];        // initializing an array                      

    // filling the array with Line and Points
    shapes[0] = new Line;
    shapes[1] = new Point;
    shapes[2] = new Line;
    shapes[3] = new Point;
    shapes[4] = new Line;
    shapes[5] = new Point;
    shapes[6] = new Line;
    shapes[7] = new Point;
    shapes[8] = new Line;
    shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

    for (int i = 0; i != 10; i++) shapes[i]->Draw();   // trying to use our Draw function taken by our abstract base class
    for (int i = 0; i != 10; i++) delete shapes[i];    // delete each pointer


    return 0; // indicates a successfully ran program
}