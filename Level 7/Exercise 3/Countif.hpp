// This is the header file for Countif 

#ifndef COUNTIF_HPP
#define COUNTIF_HPP

#include <iostream>


class isSmaller                                                 // class with same signature and functionality as global function
{
private:

    double threshold;                                           // threshold valuse set by constructors

public:
    isSmaller();                                                // constructor
    isSmaller(double value);                                    // parameterized constructor
    isSmaller(const isSmaller &other);                          // copy constructor
    ~isSmaller();                                               // destructor

    isSmaller& operator = (const isSmaller &source);            // assignment operator

    bool operator() (const double &index) const;                // () operator that takes in an index and returns a bool (functor call)
};


#endif // COUNTIF_HPP