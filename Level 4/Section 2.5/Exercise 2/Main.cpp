// Author: Kaiki Ikeda
// File: Exercise_2
// This program demonstrates how to dynamically allocate an array of pointers to Point objects on the heap.
// Each element in the array is individually constructed using a parameterized constructor and printed via dereferencing.
// All allocated memory is then properly released to avoid memory leaks.

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>

int main()
{



    Point* *arr = new Point*[3];                   // create an array of Point pointers with 3 elements on the heap
    arr[0] = new Point(1.0, 2.0);                  // first Point
    arr[1] = new Point(2.0, 3.0);                  // second point
    arr[2] = new Point(3.0, 4.0);                  // third point

    //                                          -- DRAWING --
    //
    //                                   arr = [ * ] --> Point(1.0, 2.0)
    //                                         [ * ] --> Point(2.0, 3.0)
    //                                         [ * ] --> Point(3.0, 4.0)

   
    // iterate the array and print each point
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Print: " << *arr[i] << std::endl;     // dereference the pointer arr[i] to get the actual Point object
    }


    // iterate the array again and delete each point in the array
    for (int i = 0; i < 3; i++)
    {
        delete arr[i]; // delete arr[i] pointer
    }

    //                                          -- DRAWING --
    //
    //                                   arr = [ * ] 
    //                                         [ * ] 
    //                                         [ * ] 

    delete[] arr; // delete pointer to the array


    return 0;
}