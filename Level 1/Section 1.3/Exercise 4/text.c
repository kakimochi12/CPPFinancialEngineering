// Author: Kaiki Ikeda
// File: Exercise_4
// This code is to see that 0 is interpreted as FALSE and non-zero is interpreted as TRUE. 
// We will assign a variable with a number and use ?: to print if someone is married or not

#include <stdio.h>

int main()
{
    int married = 1; 
    // initializing integer variable as 1 to indicate TRUE


    printf("Marital Status is: %s", (married == 1) ? "MARRIED" : "SINGLE"); 
    // ternary operator in one print function, depending whether the condition 
    // in the parenthese is true or false it will return TRUEVALUE : FALSEVALUE

    return 0; // Return statement indicating successful execution.
}