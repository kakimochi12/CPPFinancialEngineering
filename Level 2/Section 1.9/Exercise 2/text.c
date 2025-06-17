// Author: Kaiki Ikeda
// File: Exercise_2
// Description:
// This program is a modified version of Section 1.9 Exercise 1.
// It reads input from the keyboard and stores each line of text.
// When the user presses Enter, the line is written to a file specified by the user.
// The program continues until the user presses CTRL + A (ASCII 1), 
// at which point it prints a message and exits properly.

#include <stdio.h>      // For input/output functions (printf, fgets, fopen, etc.)
#include <stdlib.h>     // For memory allocation (malloc, realloc, free)
#include <string.h>     // For string functions (strcspn)

int main()
{
    int c;  // Variable to hold each character input
    char *buffer = malloc(10 * sizeof(char)); // Dynamic buffer to store a line of input
    int length = 0;       // Number of characters currently in the buffer
    int capacity = 10;    // Current size of the allocated buffer

    char filename[100];   // To hold the file name input by the user
    FILE *fp;             // File pointer for writing output to file

    // Prompt the user to enter a file name
    printf("Enter the file name to write to: ");
    fgets(filename, sizeof(filename), stdin); // Read the filename from user input

    // Remove the newline character from the end of the file name
    filename[strcspn(filename, "\n")] = 0;

    // Open the specified file for writing
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        // If the file couldn't be opened, show error and exit
        printf("Error opening file.\n");
        free(buffer);
        return 1;
    }

    // Read characters one by one until CTRL + A (ASCII 1) is detected
    while ((c = getchar()) != 1)
    {
        if (c == '\n') // User pressed Enter (end of line)
        {
            buffer[length] = '\0';          // Null-terminate the string
            fprintf(fp, "%s\n", buffer);    // Write the full line to the file
            length = 0;                     // Reset buffer for the next line
            continue;
        }

        // Check if buffer needs to be resized
        if (length + 1 > capacity)
        {
            capacity *= 2; // Double the buffer capacity
            char *temp = realloc(buffer, capacity); // Try reallocating
            if (temp == NULL)
            {
                // If realloc failed, clean up and exit
                printf("Memory Reallocation Failed\n");
                free(buffer);
                fclose(fp);
                return 1;
            }
            buffer = temp; // Point buffer to the newly allocated memory
        }

        buffer[length] = c; // Store the character in the buffer
        length++;           // Move to the next buffer position
    }

    // User ended the program by pressing CTRL + A
    printf("CTRL + A is a correct ending.\n");

    fclose(fp);    // Close the file
    free(buffer);  // Free the dynamically allocated memory

    return 0; // indicates a successfully ran program.
}
