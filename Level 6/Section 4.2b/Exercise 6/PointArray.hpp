// Header file for new class PointArray

#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP
#include "Array.hpp"                                               // include base class
#include "Point.hpp"                                               // include Point class 

class PointArray : public Array<Point>                             // initialize PointClass as concrete derived class of Array<Point>
{
public: 
    PointArray();                                                  // default constructor
    PointArray(int size);                                          // constructor that takes in size
    PointArray(const PointArray &other);                           // copy constructor
    ~PointArray();                                                 // destructor

    PointArray& operator = (const PointArray &source);             // assignment operator
    double Length() const;                                         // calculate length of contiguous points in the array
};

#endif  // POINTARRAY_HPP