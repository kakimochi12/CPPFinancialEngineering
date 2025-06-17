// Author: Kaiki Ikeda
// File: Exercise_1
// This program calls a function minus() and the function takes two arguments and returns the difference.

#include <stdio.h>

// This is the minus function that takes in two integers
int minus(int number_one, int number_two)
{
    return number_one - number_two;
}

int main()
{
    // initialize values x and y to pass into minus function
    int x = 45;
    int y = 23;

    // store result of minus function
    int result = 0;

    // perform function
    result = minus(x, y);

    // print the result of the function
    printf("%d\n", result);

    return 0;
}