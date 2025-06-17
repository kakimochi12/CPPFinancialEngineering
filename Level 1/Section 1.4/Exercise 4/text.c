// Author: Kaiki Ikeda
// File: Exercise_4
// This program prints two columns on the screen with temperature in Fahrenheit and the equivalent temperature in degrees Celsius

#include <stdio.h>

int main()
{
    // initialize a float variable to store celsius value
    float celsius = 0.0;

    // Making the program maintenance insensitive so the start, step size, and other variables can be easily adjusted
    int start = 0;
    int end = 300;
    int step = 20;
    int fahrenheit = 0;

    // Header text
    printf("Fahrenheit      Celsius\n");

    // Loop until fahrenheit is less than or equal to 300 degrees(end)
    while (fahrenheit <= end)
    {   
        // celsius calculation
        celsius = (5.0/9.0) * (fahrenheit - 32);
        // prints out fahrenheit and celsius values nicely aligned in the table
        printf("%6d      %10.1f\n", fahrenheit, celsius);

        // increment fahrenheit for the next looping phase.. (steps 20 in this case)
        fahrenheit += step;
    }

    return 0;

}