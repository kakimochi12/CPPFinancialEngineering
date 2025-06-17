// Author: Kaiki Ikeda
// File: Exercise_2
// This program outputs the amount of characters, words, and newlines that have been typed. (Same as exercise 1 but use a switch-case)

#include <stdio.h>
#include <ctype.h>

int main()
{
    // Initialize variables
    int c;
    int characters = 0;
    int words = 0;
    int newlines = 0;
    int in_word = 0;

    do
    {
        // process character
        c = getchar();

        // if c is the end of the file we end
        if (c == EOF)
        {
            break;
        }
        // every thing being typed is a character so increment character count
        characters++;


        switch (c)
        {
            // if its a new line, incremend new line and make sure to set in_word to 0 because we are going to a new word
            case '\n':
                newlines += 1;
                in_word = 0;
                break;

            // in case of a space or tab, set in_word to 0 because we aren't in a word anymore
            case ' ':
            case '\t':
                in_word = 0;
                break;
            
            
            default:
                // after all the conditions, if in_word is still 0 it means we just approached a new word so incremend word count and set in_word to 1
                if (in_word == 0)
                {
                    words++;
                    in_word = 1;
                }
                break;
        }

    } while (1); // Keep looping until the EOF condition is reached

    // prints results
    printf("\nRESULTS:\n");
    printf("The amount of characters is: %d\n", characters);
    printf("The amount of words is: %d\n", words);
    printf("The amount of new lines is: %d\n", newlines);

    return 0;
}
