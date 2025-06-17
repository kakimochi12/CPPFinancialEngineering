// Author: Kaiki Ikeda
// File: Exercise_2
// in this program we performed generic inheritance on our template class Array. In templates we can call functionality and define it but
// if we made array full of functionalities, it would only be limited to creating objects capable of performing specific operations, thus
// we make a generically inherited class NumericArray that takes on traits of the parent class but we "customized" it so it can do numeric operations without
// tampering with out base template.

#include "Point.hpp"               // Include Point class definition
#include "Array.hpp"               // Include Array class 
#include "ArrayException.hpp"      // Include custom exception classes for Array
#include "NumericArray.hpp"        // Include numeric array 

#include <iostream>                // For std::cout and std::endl

using namespace std;               // using directive for std::

int main()
{
    // ================================
    // Test Integer Numeric Arrays
    // ================================
    
    // creating our first test array
    NumericArray<int> test_array1(3);
    test_array1[0] = 1;
    test_array1[1] = 2;
    test_array1[2] = 3;

    // creating our second test array
    NumericArray<int> test_array2(3);
    test_array2[0] = 8;
    test_array2[1] = 8;
    test_array2[2] = 8;

    cout << "Testing the dot product for two integer arrays: " << test_array1.dotproduct(test_array2) << endl;

    // Addition Test
    NumericArray<int> sumArray = test_array1 + test_array2;
    cout << "Sum of two numeric arrays: ";
    for (int i = 0; i < sumArray.Size(); ++i) {
        cout << sumArray[i] << " ";
    }
    cout << endl;

    // Scaling Test
    NumericArray<int> scaledArray = test_array1 * 2;
    cout << "Scaling test_array1 by 2: ";
    for (int i = 0; i < scaledArray.Size(); ++i) {
        cout << scaledArray[i] << " ";
    }
    cout << endl;

    // ================================
    // Test Point Numeric Arrays
    // ================================

    // The assumptions I make about the type used as template arguments is that an array can be made but the +, * and dotproduct operations
    // we defined in our header file for NumericArray only allows for data types that are capable of those operations. I'd assume a Point doesn't allow for those operations

    // Test if we can create a numeric array with Point objects
    NumericArray<Point> point_array(3);
    point_array[0] = Point(1.0, 2.0);
    point_array[1] = Point(2.0, 3.0);           // We can create a numeric array with Point objects.. it runs, HOWEVER
    point_array[2] = Point(3.0, 4.0);

    // NumericArray<Point> scaled = point_array * 2; This line of code causes a compiler error because Point is not an element capable of numerical operations like multiplication
    cout << "Test Size() on point_array: " << point_array.Size() << endl;   // this worked.
    
    return 0; // Indicates a successfully ran program
}
