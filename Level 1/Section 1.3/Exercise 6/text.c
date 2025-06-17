// Author: Kaiki Ikeda
// File: Exercise_6
// This program shifts any integer to the right two times.

#include <stdio.h>

int main()
{
    int input_number, shifted_number;

    // Ask the user to input an integer
    printf("Enter a number to be shifted right two times: \n");
    scanf("%d", &input_number);
    
    // Perform the right bitwise shift by two
    shifted_number = input_number >> 2;

    // Prints the result after shifting
    printf("This is the shifted number %d\n", shifted_number);


    // Explains the type of shift
    printf("Since input is implicity a signed integer, this is an arithmetic shift");
    // The sign bit (leftmost bit) is preserved during the shift for signed integers

    return 0; // Return statement indicating successful execution.
}