// Author: Kaiki Ikeda
// File: Exercise_1
// This program experiemnts dynamically creating objects on the heap vs on the stack. We used pointers and the NEW syntax to assign the pointers
// We also tried using user input to dynamically size our array on the stack and learned it is not possible because our program needs to know the size at compile time
// so we dynamically sized our array on the heap.

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>

int main()
{
    // Create Point objects on the heap
    Point *p1 = new Point();
    Point *p2 = new Point(3.0, 4.0);
    Point *p3 = new Point(*p2);

    // Print using the pointer notation
    std::cout << "Distance: " << p1->Distance(*p2) << std::endl;
    std::cout << "This is p3: " << *p3 << std::endl;

    // Delete pointers to avoid memory leak
    delete p1;
    delete p2;
    delete p3;

    // ask user to input size
    int size;
    std::cout << "Enter a size: " << std::endl;
    std::cin >> size;

    // int arr[size];                       ERROR: size is not known at compile time
    Point *arr = new Point[size];           // This works but using a parameterized constructor like new Point[size](3.0, 4.0) won't work because C++ doesn't support the syntax with new[]            

    // delete arr pointer to avoid memory leak
    delete[] arr;

    return 0;
}