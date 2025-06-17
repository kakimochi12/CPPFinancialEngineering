// Author: Kaiki Ikeda
// File: Exercise_5
// This program aims to show the difference between --i and i--

#include <stdio.h>

int main()
{
    int val = 0; // Variable to store the result of the decrement operation
    int i = 100; // Initialize i with the value 100

    // Pre-decrement: --i decrements the value of i before it's used
    val = --i;
    printf("This is what --i prints out: %d\n", val); 
    printf("Value of i after --i : %d\n\n", i);

    // Reset values for post-decrement test
    val = 0;
    i = 100;

    // Post-decrement: i-- uses the current value of i, then decrements it
    val = i--;
    printf("This is what i-- prints out: %d\n", val);
    printf("Value of i after i--: %d\n", i);


    return 0; // Return statement indicating successful execution.
}