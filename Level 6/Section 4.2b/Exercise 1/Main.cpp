// Author: Kaiki Ikeda
// File: Exercise_1
// In this program we saw how static variables are managed and stored through template separation. Classes usually share the same 
// variable when the variable is static, however, with templates the static variables are shared depending on data types.

#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class definition 
#include "ArrayException.hpp"      // Include custom exception classes for Array

#include <iostream>                // For std::cout and std::endl

using namespace std;               // using directive for std::

int main()
{
    // Test the following code
    Array<int> intArray1;             // Array of int objects initialized              
    Array<int> intArray2;             // Array of int objects initialized
    Array<double> doubleArray;        // array of double objects initialized

    cout<<intArray1.DefaultSize()<<endl;           // static variable defaultsize was initialized as 10
    cout<<intArray2.DefaultSize()<<endl;           // static variable defaultsize was initialized as 10
    cout<<doubleArray.DefaultSize()<<endl;         // static variable defaultsize was initialized as 10

    intArray1.DefaultSize(15);                     // first array has default size of 15 now

    cout<<intArray1.DefaultSize()<<endl;           // The static variable in template keeps the same data depending on data types.. This would print 15
    cout<<intArray2.DefaultSize()<<endl;           // This also prints 15 because its also an integer array so it shares the same storage as array1
    cout<<doubleArray.DefaultSize()<<endl;         // We can see how the third array is a DOUBLE array so it has a separate store than the integer types

    return 0; // Indicates a successfully ran program
}
