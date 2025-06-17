// Header file for our new class Shape

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string> // for std::string type

class Shape  // our new class Shape
{
private:
    int m_id;     // private member id
public:
    Shape();                                    // default constructor (initialize the id using a rand number)
    Shape(const Shape &other);                  // copy constructor
    virtual ~Shape();                           // good practice to make destructor virtual to ensure proper cleanup if a derived object is deleted through Shape*
    
    Shape& operator = (const Shape &source);    // assignment operator that copies the id member
    virtual std::string ToString() const;               // function that returns the id as string.. This time we made it virtual to test polymorphism and avoid static binding
    int ID() const;                             // retrieve the ID of the shape
    void Print() const;                         // Template method pattern using Print() in base class that does all functionality common to all derived classes

};
#endif // SHAPE_HPP