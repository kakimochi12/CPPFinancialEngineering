// Source file for PointArray class


#include "PointArray.hpp"

PointArray::PointArray() : Array<Point>()
{
    // default constructor
}

PointArray::PointArray(int size) : Array<Point>(size)
{
    // constructor that takes a specifc size
}

PointArray::PointArray(const PointArray &other) : Array<Point>(other)
{
    // copy constructor
}

PointArray::~PointArray()
{
    // destructor
}

// Assignment operator
PointArray& PointArray::operator = (const PointArray &source)
{
    if (this == &source)                     // check for self assignment
    {
        return *this;
    }

    this->Array<Point>::operator=(source);   // call the base class assignment operator
    return *this;                            // return this object
}

// returns the total length between points in the array
double PointArray::Length() const
{
    double sum = 0.0;                                    // initialize a sum store
    for (int i = 0; i < this->Size()-1; i++)             // loop until the second to the last element to make sure i+1 is inbounds
    {
        sum += (*this)[i].Distance(((*this)[i+1]));      // add up the lengths of contiguous elements
    }

    return sum;                                          // returns the answer
}
