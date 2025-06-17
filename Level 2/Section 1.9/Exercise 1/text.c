// Author: Kaiki Ikeda
// File: Exercise_1
// This program reads the characters from the keyboard and shows them on screen. When ^A is entered, the program neds and shows a messages saying
// "CTRL + A is a correct ending."

#include <stdio.h> // include standard header file for basic c program
#include <stdlib.h> // include for dynamic memory allocation

int main()
{
    int c; // variable to store each character read from input

    // Allocate initial memory for the input buffer
    char *buffer = malloc(10 * sizeof(char)); 
    int length = 0; // number of characters currently in the buffer
    int capacity = 10; // Current allocated capacity of the buffer

    
    // Main Loop for reading characters until CTRL + A (ASCII 1) is detected
    while ((c = getchar()) != 1)
    {
        // if enter is pressed, print the current buffer as a line
        if (c == '\n')
        {
            buffer[length] = '\0'; // null terminate the string
            printf("%s\n", buffer); // THE TERMINAL PRINTS DUPLICATES. IF YOU COMMENT THIS LINE OUT, IT SHOWS NORMALLY.
            length = 0; // reset buffer for next line
            continue; // avoid continuation of loop and continue to next iteration
        }
        
        // if buffer is full, reallocate double the space
        if (length + 1 > capacity)
        {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (temp == NULL) // I learned in a C course that this is good practice: to check for allocation failure
            {
                free(buffer); // free previously allocated memory
                printf("Memory reallocation failed.\n"); // tell user it failed
                return 1; // exit with error code
            }
            buffer = temp; // if its successful we set buffer to the new memory
        }

        buffer[length] = c; // store the newly typed character in the buffer
        length++;   // increment length to the next slot
    }

    // Once the loop ends because user pressed CTRL A and enter, this will print out
    printf("CTRL + A is a correct ending.");
    free(buffer); // Free allocated memory to avoid memory leak

    return 0; // indicates a successfully ran program
}