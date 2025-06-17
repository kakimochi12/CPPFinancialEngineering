// Author: Kaiki Ikeda
// File: Exercise_1
// This program creates a function Swap() and it exchanges two variables using pointers.

#include <stdio.h> // including basic standard header file for basic C program


// Initializing a function Swap that will switch the values of two pointer variables
void Swap(int* ptr1, int* ptr2)
{
    int temporary = *ptr1; // temporary variable for ptr1 value
    *ptr1 = *ptr2; // ptr1 value will be the values of ptr2
    *ptr2 = temporary; // ptr2 value will be the valued initially stored at ptr1 which is in the temporary variable
}


// main function to run our Swap function and initialize variables to pass in to Swap
int main()
{
    int number1 = 123; // initializing first integer
    int number2 = 456; // initializing second integer

    int* i = &number1; // creating pointer for address of number1
    int* j = &number2; // creating second pointer for address of number2

    printf("i = %d\n", *i); // print the value of i before change
    printf("j = %d\n", *j); // print the values of j before change

    Swap(i, j); // performs swap between values of i and j using the function initialized above


    // This shows that the Swap function successfully executed and swapped values of i and j
    printf("The values are swapped:\n"); 
    printf("i is: %d\n", *i);
    printf("j is: %d\n", *j);

    return 0; // indicates a successfully ran program
}