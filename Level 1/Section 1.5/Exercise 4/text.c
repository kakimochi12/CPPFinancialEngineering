// Author: Kaiki Ikeda
// File: Exercise_4
// This program has a recursive function printnumber() which gets the number to be printed. It prints the number digit by digit using the
// putchar() function.

#include <stdio.h> // needed for putchar()


// recursive function to print an integer digit by digit
void printnumber(int number)
{
    // handle negative numbers by printing ('-') and converting positive
    if (number < 0)
    {
        putchar('-'); // prints negative sign
        number = -number; // changes number to positive
    }

    // If the number has more than one digit, recursively call with the number divided by 10
    // This prints all digits except the last one first 
    if (number/10)
    {
        printnumber(number/10); // Recursive call with the number excluding the last digit
    
    }

    // Print the last digit (or only digit if it's a single-digit number)
    // '0' + (a % 10) converts the digit to its ASCII character representation
    putchar('0' + (number % 10));
}

int main()
{
    int number = 465; // The number to print
    printnumber(number); // Call the recursive function
    putchar('\n'); // Print newline at the end just for cleaner output
    return 0; // exit program successfully
}