// Author: Kaiki Ikeda
// File: Exercise_2
// In this program we created our base class Shape and performed inheritance. The family members of our Shape are Point, Line, and Circle.
// We write code in the main program to answer the following questions related to Exercise 2 as instructed in the PDF

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{
    Shape s;                                    // create shape
    Point p(10, 20);                            // create point
    Line l(Point(1, 2), Point(3, 4));           // create Line

    std::cout<<s.ToString()<<std::endl;         // print shape
    std::cout<<p.ToString()<<std::endl;         // print point
    std::cout<<l.ToString()<<std::endl;         // print line

    std::cout<<"Shape ID: "<<s.ID()<<std::endl;  // ID of the shape. 
    std::cout<<"Point ID: "<<p.ID()<<std::endl;  // ID of the point. Does this work? 

    // This code works because it is a derived class from our base class. When we call a member function that belongs to our parent class, the code will run because we are seen as a part of the family.

    std::cout<<"Line ID: "<<l.ID()<<std::endl;   // ID of the line. Does this work?

    // This code works because it is a derived class from our base class as well. When we call a member function belonging to the parent class, it also works for the children.

    Shape *sp;                                   // create a pointer to a shape variable
    sp = &p;                                     // point in a shape variable. Possible?  -- This is possible.. parent class pointers CAN point to its children class
    std::cout << sp->ToString() << std::endl;    // What is printed? -- 

                                                    // We don't have virtual defined for ToString() in Shape, so sp->ToString() uses static binding.
                                                    // This means the base class version is called, even if the actual object is a Point.
                                                    // To enable dynamic binding (runtime polymorphism), we'd make ToString() virtual in Shape.


    // Create and copy Point p to new point. 
    Point p2; 
    p2=p; 
    std::cout<<p2<<", "<<p2.ID()<<std::endl;    // Is the ID copied if you do not call 
                                                // the base class assignment in point? 

                                                // If the base class assignment operator isnt explicitly called,
                                                // in the derived class, the m_id wont be copied. 
                                                // m_id is a private member of base class, the derived class can't access it directly.
                                                // if the derived assignment operator does not explicitly call Shape::operator=, the base part of the object remains unchanged

    return 0; 
}