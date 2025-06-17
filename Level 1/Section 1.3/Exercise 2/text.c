// Author: Kaiki Ikeda
// File: Exercise_2
// This file contains a function that takes in the parameters base and height as integer values and calculates the surface of a triangle.

#include <stdio.h>

// main function where the program starts

int main()
{
    // initializing integer variables for base, height, and area for triangle.
    int triangle_base = 0;
    int triangle_height = 0;

    // area triangle as a float for an accurate result
    float triangle_area = 0.0;

    
    printf("We will calculate the surface of a triangle.\n");

    // ask the user to enter a base
    printf("Enter the base: \n");
    scanf("%d", &triangle_base);

    // ask the user to enter a height
    printf("Enter the height: \n");
    scanf("%d", &triangle_height);

    // calculate the area of the triangle and print it out
    triangle_area = triangle_height * 0.5 * triangle_base;
    printf("The surface of the triangle is: %.2f", triangle_area);

    return 0; // Return statement indicating successful execution.
}