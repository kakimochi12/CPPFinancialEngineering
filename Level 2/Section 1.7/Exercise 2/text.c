// Author: Kaiki Ikeda
// File: Exercise_2
// This file has the code snippet taken from the pdf file which gives us a main which prompts the user to type a response with a cap od 30 characters
// A Length() function was implemented by me to determine the length of a string by passing string array through the function when called.

/* Calculate the length of a string */ 
#include <stdio.h> 
#define MAXLINE 30 

// String length declaration 
int Length(char str[]); 
int main() 
{ 
    char string[MAXLINE+1]; // Line of maxium 30 chars + \0 
    int c;    

    // The input character 
    int i=0;    

    // Print intro text 
    // The counter 
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE); 

    // Get the characters 
    while ((c=getchar())!=EOF && i<MAXLINE) 
    { 
        // Append entered character to string 
        string[i++]=(char)c; 
    } 
    string[i]='\0';  

    // String must be closed with \0 
    printf("String length is %d\n", Length(string)); 
    return 0; 
} 
/* Implement the Length() function here */

// creating my length function that takes in a string array, it will count the length by using pointer addition until there is no next value
int Length(char str[])
{
    int length = 0; // Initializing a length variable to store out length each step in the string
    while (*str++) // While the next character in the string exists continue the loop, it also increments the string for next iteration
    {
        length += 1; // increments 1 to length because character existed
    }
    return length; // once the loop is finished and the user hits enter CTRL + D, it returns the length of the string
}