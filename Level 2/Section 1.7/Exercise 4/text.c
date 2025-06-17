// Author: Kaiki Ikeda
// File: Exercise_4
// This program has a function DayName() that can print the day of a given day number. For example, when given 1, it will print "Day 1 is a Sunday" or given 2 it will print "Day 2 is a Monday"

#include <stdio.h> // including basic standard header file to run C program

void DayName(int number); // I had to initialize DayName function at the top or else the file does not expect or know this function exists when I run main

int main() // main code block that prompts user for a number and tells the user what the name of the day is
{
    int day; // initialize integer to hold day number
    printf("Enter a number 1-7 to show a day:\n"); // Prompt the user for a number
    scanf("%d", &day); // stores the number into day variable
    DayName(day); // performs DayName function and prints out our result
    return 0; // indicates a successfully ran program
}

// DayName function of type void because it doesnt return, it PRINTS
void DayName(int number) 
{
    // Initializing a days list. I learned that I had to use *days because we are technically storing arrays in an array and arrays are like addresses.
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // I thought of this edge case if users put some number out of range
    if (number < 1 || number > 7) // if number is less than 1 OR greater than 7 it isn't a valid number
    {
        printf("Invalid input");
        return; // gets out of the current function action
    }
    printf("Day %d is a %s\n", number, days[number-1]); // if number is valid, it will print our result in this format.
}