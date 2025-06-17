// Source file for Perpetual American Option class

#include "../include/PerpetualAmericanOption.hpp"
#include <cmath>
#include <stdexcept>


// Compute y1 for call option pricing
double PerpetualAmericanOption::y1() const
{
    double sig2 = volatility * volatility;
    double term = std::sqrt(std::pow((costOfCarry / sig2 - 0.5), 2) + 2 * riskFreeRate / sig2);
    return 0.5 - (costOfCarry / sig2) + term;
}

// Compute y2 for put option pricing
double PerpetualAmericanOption::y2() const
{
    double sig2 = volatility * volatility;
    double term = std::sqrt(std::pow((costOfCarry / sig2 - 0.5), 2) + 2 * riskFreeRate / sig2);
    return 0.5 - (costOfCarry / sig2) - term;
}

// default constructor
PerpetualAmericanOption::PerpetualAmericanOption() : Option() {}

// Parameterized constructor
PerpetualAmericanOption::PerpetualAmericanOption(const std::string &optType,
                                                 double expiry,
                                                 double strike,
                                                 double volatility,
                                                 double riskFreeRate,
                                                 double spot,
                                                 double costOfCarry)

    : Option(optType, expiry, strike, volatility, riskFreeRate, spot, costOfCarry) {}

// copy constructor
PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption &other)
    : Option(other) {}

// destructor
PerpetualAmericanOption::~PerpetualAmericanOption() {}

// Assignment operator
PerpetualAmericanOption& PerpetualAmericanOption::operator=(const PerpetualAmericanOption &source)
{
    if (this == &source) return *this;
    Option::operator=(source);
    return *this;
}

// Price function override for Perpetual American Options
double PerpetualAmericanOption::Price() const
{
    if (optType == "C")
    {
        double y1Val = y1();
        if (y1Val <= 1.0)
        {
            return spot; // No optimal stopping (the option is deep in the money)
        }
        return (strike / (y1Val - 1.0)) * std::pow(((y1Val - 1.0) / y1Val) * (spot / strike), y1Val);
    }
    else if (optType == "P")
    {
        double y2Val = y2();
        if (y2Val >= 1.0)
        {
            return strike; // No optimal stopping (deep in the money put)
        }
        return (strike / (1.0 - y2Val)) * std::pow(((y2Val - 1.0) / y2Val) * (spot / strike), y2Val);
    }
    else
    {
        throw std::runtime_error("Invalid option type in PerpetualAmericanOption::Price()");
    }
}