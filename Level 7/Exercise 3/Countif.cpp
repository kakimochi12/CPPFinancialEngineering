// This is the source file for countif

#include "Countif.hpp"

isSmaller::isSmaller() : threshold(5.0)
{
    // default constructor.. sets value to 5.0 by default like our global function
}

isSmaller::isSmaller(double value) : threshold(value)
{
    // parameterized constructor that will set our private member threshold to an assigned value
}

isSmaller::isSmaller(const isSmaller& source) : threshold(source.threshold)
{
    // copy constructor, copies source threshold value onto the object that calls this
}

isSmaller::~isSmaller()
{
    // destructor
}

// assignment operator
isSmaller& isSmaller::operator = (const isSmaller &other)
{
    if (this == &other)                                        // checking for self assignment
    {
        return *this;                                          // self assignment guard
    }

    threshold = other.threshold;                               // copy the threshold value
    return *this;                                              // return this object
}

// Function call operator that checks if each index is less than our threshold
bool isSmaller::operator() (const double &index) const
{
    return index < threshold;         // boolean statement, return True if index < threshold else False
}

