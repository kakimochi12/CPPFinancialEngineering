// This is the header file for our new class NumericArray

#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP
#include "Array.hpp"                                           // include base class

template <typename T>
class NumericArray : public Array<T>                           // our parent class
{
public:

    // constructors and destructors
    NumericArray();                                            // default constructor
    NumericArray(int size);                                    // constructor given size
    NumericArray(const NumericArray<T> &other);                // copy constructor
    ~NumericArray();                                           // destructor

    NumericArray<T>& operator = (const NumericArray<T> &source);           // assignment operator
    NumericArray<T> operator * (T factor) const;                           // Scale operator
    NumericArray<T> operator + (const NumericArray<T> &other) const;       // addition operator
    T dotproduct(const NumericArray<T> &other) const;                      // dotproduct operator

};

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif

#endif