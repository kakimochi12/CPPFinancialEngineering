// Author: Kaiki Ikeda
// File: Exercise_7
// This program takes in an input x and n where 2^n times x is the output

#include <stdio.h>

int main()
{
    int number, result, left_shift;

    // Asking for the exponent n
    printf("Enter n for 2^n: \n");
    scanf("%d", &left_shift);


    // Ask for the number to multiply
    printf("Enter a number to be multiplied by 2^n: \n");
    scanf("%d", &number);

    // Use bit shifting to compute 2*n
    result = number << left_shift;

    // show result
    printf("This is the result after (2^n) * number: %d \n", result);

    return 0; // Return statement indicating successful execution
}