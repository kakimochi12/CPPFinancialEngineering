// header file for our Perpetual American Option class

#ifndef PERPETUALAMERICANOPTION_HPP
#define PERPETUALAMERICANOPTION_HPP

#include "Option.hpp"

class PerpetualAmericanOption : public Option
{
private:

    double y1() const;    // computes y1 used in the perpetual american call option formula
    double y2() const;    // computes y2 used in the pereptual American put option formula

public:

    PerpetualAmericanOption();                              // default constructor
    PerpetualAmericanOption(const std::string &optType,     // parameterized constructor
                            double expiry,
                            double strike,
                            double volatility,
                            double riskFreeRate,
                            double spot,
                            double costOfCarry = 0.0);
    PerpetualAmericanOption(const PerpetualAmericanOption &other);   // copy constructor
    virtual ~PerpetualAmericanOption();                               // destructor

    PerpetualAmericanOption& operator=(const PerpetualAmericanOption &source);   // assignment operator

    double Price() const override;         // override pricing function to compute perpetual american option price

};

#endif  // PERPETUALAMERICANOPTION_HPP