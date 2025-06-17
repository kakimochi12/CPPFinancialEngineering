// Source file for Array to define the initialized functions in Array class

#ifndef ARRAY_CPP        // test program should now include source file instead of header so we define ARRAY_CPP if not defined
#define ARRAY_CPP        // Defines the source file

#include "Array.hpp"
#include "ArrayException.hpp"
#include <iostream>


// default constructor
// initializes array with private member size
template <typename T>
Array<T>::Array() : m_size(10), m_data(new T[m_size])
{
    
}

// parameterized constructor
// initializes array with the given size
template <typename T>
Array<T>::Array(int size)
{
    if (size <= 0)
    {
        throw std::length_error("Array size must be greater than 0");
    }

    m_size = size;
    m_data = new T[size];
}


// Copy constructor
// performs a deep copy
template <typename T>
Array<T>::Array(const Array<T> &other) : m_size(other.m_size), m_data(new T[m_size])
{
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i]; // copy individually
    }
}

//  destructor
// have to free the array memory on the heap to prevent memory leak
template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
}

// assignment operator
// handles self assignment, releases old memory and performs deep copy
template <typename T>
Array<T>& Array<T>::operator = (const Array<T> &source)
{
    if (this == &source) // check for self asignment
    {
        return *this;
    }

    delete[] m_data;   // clean existing memeory
    m_size = source.m_size;
    m_data = new T[m_size];  // allocate new memory

    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = source.m_data[i]; // deep copy for each
    }  

    return *this; // return current object
} 

// returns the size of the array
template <typename T>
int Array<T>::Size() const
{
    return m_size;
}

// Sets the element at the specified index to the given T value.
template <typename T>
void Array<T>::SetElement(int index, const T &p)
{
    if (index < 0 || index >= m_size)
    {
        // Out-of-bounds — throw an error
        throw OutOfBoundsException(index);
    }

    m_data[index] = p;
}

// returns a reference to T at the given index
// const function but still returns non const reference it seems
template <typename T>
T& Array<T>::GetElement(int index) const
{
    if (index < 0 || index >= m_size)
    {
        // Out-of-bounds — throw an error
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}

// Non const version of operator[]
// allows modification of elements, throws error if out of bounds
template <typename T>
T& Array<T>::operator [] (int index)
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index); // per assignment instructions
    }
    return m_data[index];
}

// Const version of operator[]
// Allows read only access to elements of a const array
template <typename T>
const T& Array<T>::operator [] (int index) const
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index); // per assignment instructions
    }
    return m_data[index];
}


#endif   // ARRAY_CPP


