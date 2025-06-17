// Author: Kaiki Ikeda
// File: Exercise_1
// This file contains two print macro calls. The first macro prints the variable 'a' and the second prints the variables 'a' and 'b'.
// printing happens when print1 and print2 macros accept arguments. (Macros are defined in an include file and variables get their value in the main function)

#include <stdio.h> // including system header file for normal C programming operations
#include "Defs.h" // THIS connects the header file we created to our main file (will allow us to use the macros we made)

int main() // main function to run our code.
{
    int a = 42; // initializing our first variable 'a' with integer 42
    int b = 78; // initializing our second variable 'b' with integer 78

    PRINT1(a); // Calling our first macro PRINT1 to perform its operation.. print out a
    PRINT2(a, b); // Calling our second macro PRINT2 to perform its operation.. print out a and b

    return 0; // indicates a successful end to our program
}