// Author: Kaiki Ikeda
// File: Exercise_8
// The code snippet was on the document, I put comments on the side of each printf function to predict what the output would be

#include <stdio.h> 
int main() 
{ 
    int x=2; 
    int y; 
    int z; 

    x*=3+2; // 2 * 5 = 10
    printf("x=%d\n", x); // this prints 10

    x*=y=z=4;  // 10 * 4 = 40
    printf("x=%d\n", x); // this prints 40

    x=y==z; // x = (y==z), y and z equal eachother so its 1 and so x = 1
    printf("x=%d\n", x); // prints 1
    return 0; 
} 