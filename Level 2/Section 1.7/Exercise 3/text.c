// Author: Kaiki Ikeda
// File: Exercise_3
// This is a code snippet taken from the PDF file and I have to predict what gets printed our after each loop after the macros are applied
// My responses will be in great detail next to each for loop, taking into account the reasoning behind each answer.

/* Predict what will be printed on the screen */ 

// FINAL ANSWER
//01234
//01234
//
//01234
//024
//
//43210
//43210
//43210


#include <stdio.h> 
 
#define PRD(a) printf("%d", (a) )  // Print decimal 
#define NL  printf("\n");  // Print new line 
 
// Create and initialse array 
int a[]={0, 1, 2, 3, 4}; 

int main() 
{ 
    int i; 
    int* p; 
    
    for (i=0; i<=4; i++) PRD(a[i]);    // 1
    // This for-loop prints the elements of array a from index 0 to 4.
    // PRD is a macro that prints a[i] as an integer, without spaces or line breaks.
    // So it will print: a[0], a[1], a[2], a[3], a[4] in sequence.
    NL; // New line macro defined at the top as print("\n")

    // ANSWER 1:
    // 01234
    //

    
    for (p=&a[0]; p<=&a[4]; p++) PRD(*p);   // 2 
    // p stores the address of a[0] and goes until it reaches past a[4]. p++ increments address by one so it goes to the next address
    NL; // New line macro defined at the top as print("\n")
    NL; // New line macro defined at the top as print("\n")

    // ANSWER 2:
    // 01234
    //
    //


    for (p=&a[0], i=0; i<=4; i++) PRD(p[i]);  // 3 
    // So p is storing the address of the first element of a and starts with i = 0. it increments to i each iteration and prints out p[i]. this is the same as *(p + i)
    NL; // New line macro defined at the top as print("\n")

    // ANSWER 3:
    // 01234
    //
    
    for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4 
    // p is initialized to a[0]. now p + i is performed until it goes past a + 4 = a[4]. PRD(*(p + 0)) will print out the value of 0
    // p is initialized to a[1] and i is also 1 so now it prints 1 + 1 = 2 and it is less than a[4] so it prints value of 2
    // p = a[2] and i = 2 so 2 + 2 = 4 and its not greater than the limit 4 so prints value 4
    // loop ends
    NL; // New line macro defined at the top as print("\n")
    NL; // New line macro defined at the top as print("\n")

    // ANSWER 4:
    // 024
    //
    //

    
    for (p=a+4; p>=a; p--) PRD(*p);    // 5 
    // p is set to a[4] and while p is greater than or equal to a[0] aka a, keep decrementing. it will print p each iteration.
    NL; // New line macro defined at the top as print("\n")

    // ANSWER 5:
    // 43210
    //


    
    for (p=a+4, i=0; i<=4; i++) PRD(p[-i]);   // 6 
    // Set pointer p to a + 4, which points to a[4] (the last element in the array)
    // On each iteration, p[-i] accesses elements in reverse order:
    // i = 0: p[-0] = a[4]
    // i = 1: p[-1] = a[3]
    // i = 2: p[-2] = a[2]
    // i = 3: p[-3] = a[1]
    // i = 4: p[-4] = a[0]
    // So the values are printed in reverse: a[4], a[3], ..., a[0]
    NL; // New line macro defined at the top as print("\n")

    // ANSWER 6:
    // 43210
    //
    

    for (p=a+4; p>=a; p--) PRD(a[p-a]);   // 7 
    // p is a[4] and while p is not less than a p gets decremented. first iteration is a[a[4] - a[0]] which is a[4 - 0] so a[4] = 4
    // next iteration is p = a[3] and a[a[3] - a[0]] = 3
    // continues until 0
    NL; // New line macro defined at the top as print("\n")
    
    // ANSWER 7:
    // 43210
    //


    return 0; // indicates a successfully ran code
} 