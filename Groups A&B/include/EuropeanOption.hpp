// This is the header file for our class EuropeanOption

#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include "Option.hpp"

class EuropeanOption : public Option
{
private:
    double d1() const;       // internal Black Scholes helpers
    double d2() const;

public:
    EuropeanOption();                                                // default constructor
    EuropeanOption(const std::string &optType,                       // parameterized constructor
                   double expiry,
                   double strike,
                   double volatility,
                   double riskFreeRate,
                   double spot,
                   double costOfCarry = 0.0);
    EuropeanOption(const EuropeanOption &source);                    // copy constructor
    virtual ~EuropeanOption();                                       // Destructor

    EuropeanOption& operator = (const EuropeanOption &other);        // Assignment Operator

    double Price() const override;            // override function from Base Class

    double Delta() const;    // exact Delta
    double Gamma() const;    // exact Gamma

};

#endif  // EUROPEANOPTION_HPP