// Author: Kaiki Ikeda
// File: Exercise_3
// This program prints factorial of a number using recursion.

// ** COMPILE BOTH FILES Main.c AND Print.c as ONE and it will work!

#include <stdio.h>

// function for print() tells the compiler the function exists and takes an integer
void print(int a);

int main()
{
    int number = 40; // Declare and initialize a variable number with the value 40
    print(number); // Call the print function and pass number as an argument
    return 0; // Return 0 to indicate successful program termination
}