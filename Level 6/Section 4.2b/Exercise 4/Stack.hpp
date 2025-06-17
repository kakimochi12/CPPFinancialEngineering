// Header file for our class Stack

#ifndef STACK_HPP
#define STACK_HPP
#include "Array.hpp"           // for composition

template <typename T>          // stack of any type template
class Stack                    // initialize class
{
private:
    Array<T> m_data;           // composition - Array from the array class
    int m_current;             // store current index of the array

public:
    Stack();                                            // constructor
    Stack(int size);                                    // constructor that takes a size
    Stack(const Stack<T> &other);                       // copy constructor
    ~Stack();                                           // destructor

    Stack<T>& operator = (const Stack<T> &source);      // assignment operator

    void Push(const T& variable);                       // push element onto the stack
    T Pop();                                            // pop from the stack
};

#include "Stack.cpp"
#endif // STACK_HPP
