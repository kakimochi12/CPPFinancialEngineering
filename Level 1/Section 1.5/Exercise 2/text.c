// Author: Kaiki Ikeda
// File: Exercise_2
// This program prints factorial of a number using recursion.

#include <stdio.h>

int factorial(int number)
{
    // base case for recursion
    if (number <= 1)
    {
        return 1;
    }
    
    // return with recursive function
    return number * (factorial(number-1));
}

int main()
{
    // initialize number to pass in function
    int number = 4;

    // store result of function
    int result = 0;

    // perform function on number
    result = factorial(number);

    // print out result of function
    printf("%d", result);

    return 0;
}