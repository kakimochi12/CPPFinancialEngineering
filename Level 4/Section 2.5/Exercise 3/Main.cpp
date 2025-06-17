// Author: Kaiki Ikeda
// File: Exercise_3
// We created a new Array class implementing dynamic array on the heap. The data members of the array class are an array of Point objects
// and the size of the array. We implemented various functions and constructors that allow us to edit and access the members of the array class.

#include "Array.hpp"
#include <iostream>

int main()
{
    // Test default constructor and Size()
    Array a;
    std::cout << "Size of array is: " << a.Size() << std::endl;

    // Test SetElement and operator[]
    Point p1(1.0, 2.0);
    a.SetElement(2, p1);
    std::cout << "Element set at index 2 should be Point(1.0, 2.0): " << a[2] << std::endl;

    // Test GetElement
    std::cout << "Testing our GetElement() function: " << a.GetElement(2) << std::endl;

    // Test parameterized constructor and operator[]
    Array b(3);
    b[0] = Point(1.0, 2.0);
    b[1] = Point(3.0, 4.0);

    std::cout << "b[0]: " << b[0] << std::endl;
    std::cout << "b[1]: " << b[1] << std::endl;

    // Test direct modification of coordinates through reference
    b[2].X(7.0);
    b[2].Y(8.0);
    std::cout << "b[2]: " << b[2] << std::endl;

    // Test out-of-bounds access handling
    std::cout << "b[-1] should return b[0]: " << b[-1] << std::endl;

    // Test const version of operator[]
    const Array c = b;
    std::cout << "getting from a const array: " << c[0] << std::endl;

    return 0;
}
