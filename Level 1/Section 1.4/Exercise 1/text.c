// Author: Kaiki Ikeda
// File: Exercise_1
// This program outputs the amount of characters, words, and newlines that have been typed.

#include <stdio.h>
#include <ctype.h>
int main()
{
    // Initialize variables so we can count requirements
    int c; // This is to scan the current character with getchar()
    int characters = 0;
    int words = 0;
    int newlines = 0;
    int in_word = 0; // This is like a boolean tracker. 0 if not in a word and 1 if we are

    // Loop through while input is being typed until CTRL + D or end of file is reached
    while ((c = getchar()) != EOF)
    {
        characters += 1; // Every thing in the file is considered a character so keep counting while things are being typed

        // if a character is new line we increment count for newlines
        if (c == '\n')
        {
            newlines += 1;
            in_word = 0;
        }

        // if c is a space, then we change our boolean tracker to 0 because it means we got out of a word
        if (isspace(c))
        {
            in_word = 0;
        }

        // if the top is not true and the boolean tracker is 0. It means we are on a new word so increment count for words 
        // we also change boolean tracker to 1 because we are in a word
        else if (in_word == 0)
        {
            words += 1;
            in_word = 1;
        }
    }

    // After user hits CTRL D on a new line, it prints these out.
    printf("RESULTS: \n");
    printf("The amount of characters is: %d\n", characters);
    printf("The amount of words is: %d\n", words);
    printf("The amount of new lines is: %d", newlines);

    return 0;
}