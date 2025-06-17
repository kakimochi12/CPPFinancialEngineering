// Author: Kaiki Ikeda
// File: freq.c
// This program counts how many times each of the numbers 0-4 have been typed using a switch-case. 

#include <stdio.h>

int main()
{
    int c = 0; // initialize variable to process each character that is typed
    int count_zero = 0; // intialize count for zeroes
    int count_one = 0; // initialize count for ones
    int count_two = 0; // initialize count for twos
    int count_three = 0; // intialize count for threes
    int count_four = 0; // initizalize count for fours
    int other_count = 0; // initialize count for other characters
    
    // do while loop until EOF condition is met when user goes to new line and types CTRL + d
    do
    {
        // process character
        c = getchar();

        // if end of file, loop will break
        if (c == EOF)
        {
            break;
        }

        // switch if c is a character
        switch (c)
        {
            // increment zero count if c is 0
            case '0':
                count_zero++;
                break;
            
            // increment one count if c is 1
            case '1':
                count_one++;
                break;

            // increment one count if c is 2
            case '2':
                count_two++;
                break;
            
            // increment one count if c is 3
            case '3':
                count_three++;
                break;

            // increment one count if c is 4
            case '4':
                count_four++;
                break;
            
            // if its not a character 0-4, then other count gets incremented
            default:
                other_count++;
                break;
        }
    } while (1); // while true


    // print results
    printf("RESULTS:\n");
    printf("0 count: %d\n", count_zero);
    printf("1 count: %d\n", count_one);
    printf("2 count: %d\n", count_two);
    printf("3 count: %d\n", count_three);
    printf("4 count: %d\n", count_four);
    printf("Number of other characters: %d\n", other_count);
    

    return 0;
}