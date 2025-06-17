// Source file for Numeric Array

#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP

#include "Array.hpp"
#include "NumericArray.hpp"

template <typename T>
NumericArray<T>::NumericArray() : Array<T>()
{
    // This calls the default constructor of Array<T>
}

template <typename T>
NumericArray<T>::NumericArray(int size) : Array<T>(size)
{
    // This calls the constructor with size of Array<T>
}

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T> &other) : Array<T>(other)
{
    // This calls Array<T> copy constructor
}   

template <typename T>
NumericArray<T>::~NumericArray()
{
    // destructor
}

// Assignment operator for numeric array
template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T> &source)
{
    // avoid self assignment
    if (this == &source)
    {
        return *this;
    }

    // call base class assignment
    this->Array<T>::operator=(source);

    // return the current object
    return *this;
}

// Scale elements with a factor
template <typename T>
NumericArray<T> NumericArray<T>::operator * (T scale) const
{
    // create a store of the same size for array
    NumericArray<T> result(this->Size());

    // loop through one pass O(n)
    for (int i = 0; i < this->Size(); i++)
    {
        // our store will keep the scaled version for each index
        result[i] = (*this)[i] * scale;    
    }

    // gives the result of the scaled array
    return result;  
}

// add the elements of two numeric arrays
template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T> &other) const
{
    // throw an exception if arrays are different in size
    if (other.Size() != this->Size())
    {
        throw SizeMismatchException();
    }

    // create a store for our result
    NumericArray<T> result(this->Size());

    // one pass loop to add this array and other array into our result for each index
    for (int i = 0; i < this->Size(); i++)
    {
        result[i] = (*this)[i] + other[i];
    }


    // returns our answer
    return result;
}

// calculate the dot product of two arrays
template <typename T>
T NumericArray<T>::dotproduct(const NumericArray<T> &other) const
{
    // throw an exception if arrays are different in size
    if (other.Size() != this->Size())
    {
        throw SizeMismatchException();
    }

    T result = 0;

    // loop through each element and calculate the dot product
    for (int i = 0; i < this->Size(); i++)
    {
        result += (*this)[i] * other[i];
    }

    return result;
}

#endif // NUMERICARRAY_CPP
