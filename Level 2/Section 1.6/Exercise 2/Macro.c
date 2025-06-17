// Author: Kaiki Ikeda
// File: Exercise_2
// This file creates two macros in the Def.h file called MAX2 which takes in two variables and returns the maximum values AND MAX3 that takes three variables
// and returns the max of all of them. I used recursion with MAX2 to find MAX3 and I include the Def.h file into our main

#include <stdio.h> // include standard library for basic C programming
#include "Defs.h" // including our very own headerfile that contains our macros

int main() // main function where we will initialize variables and run our macros
{
    int x = 2; // initialize integer x
    int y = 3; // initialize integer y
    int z = 4; //  initialize integer z

    // This prints out the result of our MAX2
    printf("This is the result of MAX2: %d\n", MAX2(x, y)); 

    // This prints out the result of our MAX3
    printf("This is the result of MAX3: %d\n", MAX3(x, y, z));

    return 0; // Indicates a successfuly ran program
}
