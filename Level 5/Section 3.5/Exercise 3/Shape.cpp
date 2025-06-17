// this is the source file to initialize our member functions that are a part of our Shape class

#include "Shape.hpp" // including our header file

#include <stdlib.h> // including stdlib for rand()
#include <string> // include so we can use std::string type
#include <iostream> // standard c++ source for basic program and cout cin etc.


// Shape constructor with colon syntax that assigns a random int to m_id
Shape::Shape() : m_id(rand())
{

}

// Shape copy constructor that assigns m_id to the other m_id
Shape::Shape(const Shape &other) : m_id(other.m_id)
{

}

// Shape destructor
Shape::~Shape()
{
    // destructor
    std::cout << "shape Destructor was called." << std::endl;
}

// Shape assginment operator
Shape& Shape::operator = (const Shape &source)
{
    if (this == &source) // checks if its already assigned
    {
        return *this;   // then return this pointer
    }
    
    // assign m_id to be the source m_id
    m_id = source.m_id;

    // return this pointer
    return *this;
}

// presents m_id as a string
std::string Shape::ToString() const
{
    return "ID: " + std::to_string(m_id);
}

// gets the ID of the shape
int Shape::ID() const
{
    return m_id;
}