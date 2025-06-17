// Author: Kaiki Ikeda
// File: Exercise_2
// This program outputs the amount of characters, words, and newlines that have been typed. (Same as exercise 1 but use a do while insted of a while)

#include <stdio.h>
#include <ctype.h>

int main()
{
    // Initialize variables so we can count requirements; same as exercise 1
    int c;
    int characters = 0;
    int words = 0;
    int newlines = 0;
    int in_word = 0;

    do
    {
        // first time through c isn't initialized yet so we do this
        c = getchar();

        // check if c is end of file
        if (c == EOF)
        {
            break;
        }

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
    } while (1); // keep running while true and there will be a condition inside the do that will let you know when to stop

    // After user hits CTRL D on a new line, it prints these out.
    printf("RESULTS: \n");
    printf("The amount of characters is: %d\n", characters);
    printf("The amount of words is: %d\n", words);
    printf("The amount of new lines is: %d\n", newlines);

    return 0;
    
}