// Source file for Array to define the initialized functions in Array class

#include "Array.hpp"
#include <iostream>


// default constructor
// initializes the array with 10 point objects using the dault constructor for point
Array::Array()
{
    m_size = 10;
    m_data = new Point[m_size];
}

// parameterized constructor
// initializes the array with the given size
Array::Array(int size)
{
    m_size = size;
    m_data = new Point[m_size];
}


// Copy constructor
// performs a deep copy
Array::Array(const Array &other)
{
    m_size = other.m_size;
    m_data = new Point[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i]; // copy individually
    }
}

//  destructor
// have to free the array memory on the heap to prevent memory leak
Array::~Array()
{
    delete[] m_data;
}

// assignment operator
// handles self assignment, releases old memory and performs deep copy
Array& Array::operator = (const Array &source)
{
    if (this == &source) // check for self asignment
    {
        return *this;
    }

    delete[] m_data;   // clean existing memeory
    m_size = source.m_size;
    m_data = new Point[m_size];  // allocate new memory

    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = source.m_data[i]; // deep copy for each
    }  

    return *this; // return current object
} 

// returns the size of the array
int Array::Size() const
{
    return m_size;
}

// Sets the element at the specified index to the given Point value.
// If the index is out of bounds, do nothing (per assignment instructions).
void Array::SetElement(int index, const Point &p)
{
    if (index < 0 || index >= m_size)
    {
        // Out-of-bounds — throw an error
        throw -1;
    }

    m_data[index] = p;
}

// returns a reference to the point at the given index
// const function but still returns non const reference it seems
Point& Array::GetElement(int index) const
{
    if (index < 0 || index >= m_size)
    {
        // Out-of-bounds — throw an error
        throw -1;
    }

    return m_data[index];
}

// Non const version of operator[]
// allows modification of elements, throws error if out of bounds
Point& Array::operator [] (int index)
{
    if (index < 0 || index >= m_size)
    {
        throw -1; // per assignment instructions
    }
    return m_data[index];
}

// Const version of operator[]
// Allows read only access to elements of a const array
const Point& Array::operator [] (int index) const
{
    if (index < 0 || index >= m_size)
    {
        throw -1;
    }
    return m_data[index];
}


