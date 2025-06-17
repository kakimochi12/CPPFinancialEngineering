// Author: Kaiki Ikeda
// File: Array.hpp
// Header file that defines the Array class a custom dynamic array for storing T objects on the heap.
// The class encapsulates memory management, deep copying, safe access, and overloads the subscript operator
// to behave like a native C++ array.

#ifndef ARRAY_HPP
#define ARRAY_HPP
 


template <typename T>                  // declaring the array class as a template T
class Array
{
private:
    T* m_data;   // Pointer to a dynamically allocated array of our new template objects
    int m_size;      // Size of the array (number of T elements)

public:
    // Default constructor creates an array with a default size (e.g., 10 elements)
    Array();

    // Constructor with size argument allocates an array with the given number of T objects
    Array(int size);

    // Copy constructor performs a deep copy of another Array object
    Array(const Array& other);

    // Destructor releases the dynamically allocated memory to prevent leaks
    ~Array();

    // Getter for the size of the array
    int Size() const;

    // Sets the T object at a specific index
    void SetElement(int index, const T& p);

    // Gets a reference to the T (our template) at a specific index
    T& GetElement(int index) const;

    // Subscript operator for non-const objects allows read/write access
    T& operator[](int index);

    // Subscript operator for const objects allows read-only access
    // Needed so const Arrays can still be accessed safely
    const T& operator[](int index) const;

    // Assignment operator handles deep copy and self assignment safely
    Array& operator=(const Array& source);
};

#include "Array.cpp"         // Include the source file explicitly


// #ifndef Array_cpp
// #include "Array.cpp"
// #endif
//
// So when there is Array<Point> points(10), the compiler needs the entire implementation of Array<T>.
// if it can't see the implementations, it will cause a linker error.
// We can't just include Array.cpp directly because it must be included where it is instantiated, not just declared
// FORCES VISIBILITY - compiler can have full access to the code at instantiation.



#endif