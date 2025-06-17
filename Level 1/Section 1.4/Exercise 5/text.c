// Author: Kaiki Ikeda
// File: Exercise_5
// This program prints two columns on the screen with temperature in Fahrenheit and the equivalent temperature in degrees Celsius

// ***I am assuming comma in the instructions refers to decimal***

#include <stdio.h>

int main()
{
    // Header text
    printf("Celsius      Fahrenheit\n");

    // initialize float variable to store fahrenheit value
    float fahrenheit = 0.0;

    // loop each celsius value one step at a time while less than or equal to 19
    for (int celsius = 0; celsius <= 19; celsius++)
    {
        // fahrenheit calculation
        fahrenheit = (celsius * (9.0/5.0)) + 32;

        // print results
        printf("%4d     %10.1f\n", celsius, fahrenheit);
    }

    return 0;
}