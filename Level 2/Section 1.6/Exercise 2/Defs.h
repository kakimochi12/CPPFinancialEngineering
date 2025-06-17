// This is the header file for my two macros MAX2 and MAX3

#ifndef DEFS_H // prevent multiple inclusions of header file
#define DEFS_H // defines header file if the header file was not defined

#define MAX2(x, y) ((x>y)? x:y) // defining our macro MAX2 to take two values and return the bigger value using ternary operator we learned in Level 1
#define MAX3(x, y, z) ((MAX2(x, y) > z)? MAX2(x, y):z) // degining our macro MAX3 using recursion. It uses the answer we get from MAX2 and we implement a ternary operatoer for it once again

#endif // end the ifndef and endif directive.