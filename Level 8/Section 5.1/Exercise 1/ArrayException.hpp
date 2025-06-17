// Header file for our ArrayException and OutOfBoundsException classes

#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP

#include <string>  // Needed for std::string and std::to_string

// Abstract base class for exceptions related to Array operations
class ArrayException
{
public:
    // Pure virtual function that must be implemented by derived classes
    // Returns a string message describing the exception
    virtual std::string GetMessage() const = 0;

    // Virtual destructor should be added in base classes for safety
    virtual ~ArrayException() {}
};

// Derived class representing an out-of-bounds access exception
class OutOfBoundsException : public ArrayException
{
private:
    int m_index;  // The invalid index that caused the exception

public:
    // Constructor initializing the index that was out of bounds
    OutOfBoundsException(int index) : m_index(index) {}

    // Override the GetMessage function to return a descriptive error message
    std::string GetMessage() const override
    {
        return "Index " + std::to_string(m_index) + " is out of bounds!";
    }
};

// Derived class representing a size mismatch exception for NumericArray operations
class SizeMismatchException : public ArrayException
{
public:
    // constructor
    SizeMismatchException() {}

    // Override the GetMessage function to return descriptive error message
    std::string GetMessage() const override
    {
        return "The numeric arrays are of different sizes and cannot be added or operated on.";
    }
};

#endif  // End of header guard
