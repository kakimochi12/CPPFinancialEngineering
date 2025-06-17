// This is the header file where I put two macros

#ifndef DEFS_H // prevent multiple inclusions of header file
#define DEFS_H //  Define DEFS_H if not already defined

#define PRINT1(a) printf("%d\n", a) // Defining our first macro called PRINT1 which takes in a variable a and prints it out
#define PRINT2(a, b) printf("%d and %d\n", a, b) // Defining our second macro called PRINT2 which takes in variables a and b, then prints it out

// I do remember in the course that a minor setback of macros is that it can't specify what data type it wants to take in so for the sake of this assignment
// it states that I can create a and b in the main function where they get there values so I set them as INTEGERS



#endif // end of the ifndef and endif directive.