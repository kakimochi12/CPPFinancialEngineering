// Author: Kaiki Ikeda
// File: Exercise_1
// This file prints the contents of a struct called Article and it has the following characteristics of Article Number, Quantity, Description.
// There is also a Print function which takes in the address of a struct as a parameter. It prints the contents of the struct through calling this function in main.

#include <stdio.h> // Including standard header file to run basic C program


// Initializing type struct Article consisting of three elements
struct Article
{
   int article_number; // Integer store called article_number
   int quantity; // integer store called quantity
   char description[21]; // This takes in a string of length 20 max leaving the extra one for \0.
};

// Initializing a struct and designating a value for each element
struct Article my_article = {.article_number = 6, .quantity = 10, .description = "description"};

// Print function that takes in a pointer (address of struct) and will print the contents of the struct
void Print(struct Article *pointer)
{
    printf("This is the variable for Article Number: %d\n", (*pointer).article_number); // prints the article number variable
    printf("This is the variable for quantity: %d\n", (*pointer).quantity); // Prints the quantity variable
    printf("This is the description: %s\n", (*pointer).description); // Prints the description string
}

// main function to perform our program
int main()
{
    struct Article *struct_pointer = &my_article; // creating a pointer to the address of the struct we made
    Print(struct_pointer); // perform the Print function we made that will print the contents of the struct

    return 0; // indicates a successfully ran program.
}