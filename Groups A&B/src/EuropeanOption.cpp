// This is the source file for EuropeanOption

#include "../include/EuropeanOption.hpp"
#include "../include/Utility.hpp"
#include <cmath>
#include <stdexcept>

// default constructor
EuropeanOption::EuropeanOption() : Option() {}

// parameterized constructor
EuropeanOption::EuropeanOption(const std::string &optType,                  
                               double expiry,
                               double strike,
                               double volatility,
                               double riskFreeRate,
                               double spot,
                               double costOfCarry) 
        : Option(optType, expiry, strike, volatility, riskFreeRate, spot, costOfCarry) {}

// copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption &source) : Option(source) {}

// Destructor
EuropeanOption::~EuropeanOption() {}

// Assignment Operator
EuropeanOption& EuropeanOption::operator=(const EuropeanOption &other)
{
    if (this == &other)
    {
        return *this;
    }

    Option::operator=(other);        // delegate to base class
    return *this;
}

// PRIVATE HELPER FUNCTIONS for d1 and d2
double EuropeanOption::d1() const
{
    return (std::log(spot/ strike) + 
    (costOfCarry + 0.5 * volatility * volatility) * expiry)
    / (volatility * std::sqrt(expiry));
}

double EuropeanOption::d2() const
{
    return d1() - volatility * std::sqrt(expiry);
}

// Pricing Function Override
double EuropeanOption::Price() const
{
    double D1 = d1();          // d1 for cumulative distribution function 
    double D2 = d2();          // d2 for cumulative distribution function
 
    // if it is a call perform this block
    if (optType == "C")
    {
        return spot * std::exp((costOfCarry - riskFreeRate) * expiry) * N(D1)
        - strike * std::exp(-riskFreeRate * expiry) * N(D2);
    }

    // if it is a put perform this block
    else if (optType == "P")
    {
        return strike * std::exp(-riskFreeRate * expiry) * N(-D2)
        - spot * std::exp((costOfCarry - riskFreeRate) * expiry) * N(-D1);
    }

    // Invalid type
    else
    {
        throw std::runtime_error("Invalid Option Type. Use 'P' or 'C'.");
    }
}

// Function to calculate exact delta
double EuropeanOption::Delta() const 
{
    double d1 = (log(spot / strike) + (costOfCarry + 0.5 * volatility * volatility) * expiry)      // d1 formula
                / (volatility * sqrt(expiry));

    if (optType == "C") 
    {
        return exp((costOfCarry - riskFreeRate) * expiry) * N(d1);            // Delta for call
    } else 
    {
        return -exp((costOfCarry - riskFreeRate) * expiry) * N(-d1);          // delta for put
    }
}

// function to calculate the exact gamma
double EuropeanOption::Gamma() const 
{
    double d1 = (log(spot / strike) + (costOfCarry + 0.5 * volatility * volatility) * expiry)     // d1 formula
                / (volatility * sqrt(expiry));
    double denominator = spot * volatility * sqrt(expiry);                         
    return (exp((costOfCarry - riskFreeRate) * expiry) * n(d1)) / denominator;                      // gamma 
}


