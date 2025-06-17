// Author: Kaiki Ikeda
// File: Exercise_3
// The code snippet was on the document, I put comments on the side of each printf function to predict what the output would be
#include <stdio.h> 
int main() 
{ 
    int x; 
    // initialized variable that stores integer

    x=-3+4*5-6; 
    printf("x=%d\n", x); 
    // Following the order of operations (PEMDAS): 
    // 4 * 5 = 20, then -3 + 20 = 17, then 17 - 6 = 11


    x=3+4%5-6; 
    printf("x=%d\n", x); 
    // 4 % 5 = 4 (since 4 < 5, remainder is 4),
    // then 3 + 4 = 7, and 7 - 6 = 1

    x=-3*4%-6/5; 
    printf("x=%d\n", x); 
    // Left to right:
    // -3 * 4 = -12
    // -12 % -6 = 0 (since -12 is evenly divisible by -6)
    // 0 / 5 = 0

    x=(7+6)%5/2; 
    printf("x=%d\n", x); 
    // Parentheses first: 7 + 6 = 13
    // 13 % 5 = 3
    // 3 / 2 = 1 (integer division truncates the decimal)


    return 0; // Return statement indicating successful execution.
}