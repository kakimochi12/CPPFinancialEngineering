// Author: Kaiki Ikeda
// File: Exercise_9
// The code snippet was on the document, I put comments on the side of each printf function to predict what the output would be

#include <stdio.h> 
int main() 
{ 
    int x=1; 
    int y=1; 
    int z=1; 
    x+=y+=x; // x += (y += x) so it would be x += (1 + 1) so in the end x = 3
    printf("%d\n\n", (x<y)?y:x);  // so this was the ternary operator we learned earlier (STATEMENT)?true_val:false_val. This would output 3 because x is NOT less than y
    printf("%d\n", (x<y)?x++:y++); // This prints 2 
    printf("%d\n", x); // This outputs 3
    printf("%d\n", y); // This outputs 3
    return 0; 
}  