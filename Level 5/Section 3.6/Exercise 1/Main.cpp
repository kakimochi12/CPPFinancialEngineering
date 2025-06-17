// Author: Kaiki Ikeda
// File: Exercise_1
// In this program we performed bounds checking on our array class but putting if statements to check if index is out of bounds. We then
// would throw -1 as an error. To improve our code we also implemented a try and catch to attmept a run at our code and if it detected throw -1,
// the catch would capture the int err and output our custom error statement



#include "Point.hpp"
#include "Array.hpp"

#include <iostream>


int main()
{
    //  Array arr1;
    //  std::cout << "Trying to access an element out of bounds: " << arr1[-1] << std::endl;
    //
    //  When this code is run, it says "terminate called after throwing an instance of 'int'". Our if statement to check if element is out of bounds was triggered and it threw an error

    // using a try block to attempt a run at our code
    try
    {
        Array arr1;                                                                                    // create an array
        std::cout << "trying to set an element out of bounds: " << arr1.GetElement(-11) << std::endl;  // try to get an element at index -11
    }
    catch(int err)  // if the function throws -1 it catches it here
    {
        std::cout << "Caught an exception! Index is out of bounds." << std::endl;                       // customized error output as a result of our catch
    }
    

    return 0; // indicates a successfully ran program
}