// Header file for StackException
#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP
#include <string>

class StackException
{
public:

    // Pure virtual function that must be implemented by derived classes
    // Returns a string message describing the exception
    virtual std::string GetMessage() const = 0;

    // Virtual destructor should be added in base classes for safety
    virtual ~StackException() {}
};

// Derived class of StackException that throws an error if user tries to push when stack is full
class StackFullException : public StackException
{
public:
    std::string GetMessage() const override
    {
        return "Stack is already full. Cannot push more elements.";
    }
};

// Derived class of StackException that throws an error if user tries to pop when stack is empty
class StackEmptyException : public StackException
{
public:
    std::string GetMessage() const override
    {
        return "Stack is empty, no values can be popped.";
    }
};

#endif // STACKEXCEPTION_HPP