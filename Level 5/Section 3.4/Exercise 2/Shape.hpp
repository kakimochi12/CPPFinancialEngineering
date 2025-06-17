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
    ~Shape();
    
    Shape& operator = (const Shape &source);    // assignment operator that copies the id member
    std::string ToString() const;               // function that returns the id as string
    int ID() const;                             // retrieve the ID of the shape

};
#endif // SHAPE_HPP