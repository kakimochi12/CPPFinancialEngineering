// Author: Kaiki Ikeda
// File: Array.hpp
// Header file that defines the Array class a custom dynamic array for storing Point objects on the heap.
// The class encapsulates memory management, deep copying, safe access, and overloads the subscript operator
// to behave like a native C++ array.

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"  // Required for Point class, which this array will store


class Array
{
private:
    Point* m_data;   // Pointer to a dynamically allocated array of Point objects
    int m_size;      // Size of the array (number of Point elements)

public:
    // Default constructor creates an array with a default size (e.g., 10 elements)
    Array();

    // Constructor with size argument allocates an array with the given number of Points
    Array(int size);

    // Copy constructor performs a deep copy of another Array object
    Array(const Array& other);

    // Destructor releases the dynamically allocated memory to prevent leaks
    ~Array();

    // Getter for the size of the array
    int Size() const;

    // Sets the Point at a specific index
    void SetElement(int index, const Point& p);

    // Gets a reference to the Point at a specific index
    Point& GetElement(int index) const;

    // Subscript operator for non-const objects allows read/write access
    Point& operator[](int index);

    // Subscript operator for const objects allows read-only access
    // Needed so const Arrays can still be accessed safely
    const Point& operator[](int index) const;

    // Assignment operator handles deep copy and self assignment safely
    Array& operator=(const Array& source);
};


#endif