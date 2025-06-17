// Source file for our Stack class

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "StackException.hpp"

// default constructor initialize stack with template size
template <typename T, int size>
Stack<T, size>::Stack() : m_data(size), m_current(0)
{
    std::cout << "Initializing stack with size: " << size << std::endl;

    if (size <= 0)
    {
        throw std::invalid_argument("Stack size must be greater than 0");
    }
}


template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size> &other) : m_data(other.m_data), m_current(other.m_current)
{
    // copy constuctor for stack; copies contents and current index of other stack
}

template <typename T, int size>
Stack<T, size>::~Stack()
{
    // destructor
}

// assignment operator
template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size> &source)
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
template <typename T, int size>
void Stack<T, size>::Push(const T &variable)
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
template <typename T, int size>
T Stack<T, size>::Pop()
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