// Source file for our Stack class

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack() : m_data(10), m_current(0)
{
    // default constructor
}

template <typename T>
Stack<T>::Stack(int size) : m_data(size), m_current(0)
{
    // constructor that initializes a stack of length size
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other) : m_data(other.m_data), m_current(other.m_current)
{
    // copy constuctor for stack; copies contents and current index of other stack
}

template <typename T>
Stack<T>::~Stack()
{
    // destructor
}

// assignment operator
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T> &source)
{
    if (this == &source)                                        // check for slef assignment
    {
        return *this;
    }

    this->m_data = source.m_data;                               // assign source data to this
    this->m_current = source.m_current;                         // assign current index to this

    return *this;                                               // return this object
}   

// Push function for stack (appends to the stack)
template <typename T>
void Stack<T>::Push(const T &variable)
{
    if (m_current >= m_data.Size())                                                       // check for overflow
    {
        throw std::overflow_error("Stack is already full. Cannot push more elements.");
    }

    m_data[m_current] = variable;                                                         // push element in the current index
    ++m_current;                                                                          // increment index
}

// Pop function for our stack that returns the top element of the stack
template <typename T>
T Stack<T>::Pop()
{
    if (m_current == 0)                                                                    // check if stack is empty
    {
        throw std::underflow_error("Stack is empty, cannot pop any elements.");
    }

    --m_current;                                                                           // decrement to the top element of the stack
    return m_data[m_current];                                                              // return the top element
}

#endif // STACK_CPP