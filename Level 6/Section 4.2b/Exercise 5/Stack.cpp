// Source file for our Stack class

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "StackException.hpp"

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
    try
    {
        // Try to set element in the array
        m_data.SetElement(m_current, variable);
        ++m_current;        // if successful increment index
    }
    catch(const OutOfBoundsException &e)
    {
        // Translate to StackFullException
        throw StackFullException();
    }
    
}

// Pop function for our stack that returns the top element of the stack
template <typename T>
T Stack<T>::Pop()
{
    try
    {
        --m_current;                                    // move the index back
        return m_data.GetElement(m_current);            // try to return the top of the stack 
    }
    catch(const OutOfBoundsException& e)
    {   
        ++m_current;                                    // reset top original position
        throw StackEmptyException();                    // translate to stack empty exception
    }
    
}

#endif // STACK_CPP