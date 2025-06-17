// Header file for our class Stack

#ifndef STACK_HPP
#define STACK_HPP
#include "Array.hpp"           // for composition

template <typename T, int size>     // stack of any type template
class Stack                         // initialize class
{
private:
    Array<T> m_data;           // composition - Array from the array class
    int m_current;             // store current index of the array

public:
    Stack();                                            // constructor
    Stack(const Stack<T, size> &other);                       // copy constructor
    ~Stack();                                           // destructor

    Stack<T, size>& operator = (const Stack<T, size> &source);      // assignment operator

    void Push(const T& variable);                       // push element onto the stack
    T Pop();                                            // pop from the stack
};

#include "Stack.cpp"
#endif // STACK_HPP
