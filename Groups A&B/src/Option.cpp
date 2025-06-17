// Source file for our Option Class

#include "../include/Option.hpp"

// Default Constructor
Option::Option() : expiry(0), strike(0), volatility(0), riskFreeRate(0), spot(0), costOfCarry(0), optType("C") {}

// Paramaterized Constructor
Option::Option(const std::string &optType,
        double expiry, 
        double strike,
        double volatility,
        double riskFreeRate,
        double spot,
        double costOfCarry)
    : expiry(expiry), strike(strike), volatility(volatility), 
      riskFreeRate(riskFreeRate), spot(spot), costOfCarry(costOfCarry),
      optType(optType) {}

// Copy Constructor
Option::Option(const Option &other) 
    : expiry(other.expiry), strike(other.strike), volatility(other.volatility), 
      riskFreeRate(other.riskFreeRate), spot(other.spot), costOfCarry(other.costOfCarry),
      optType(other.optType) {}

// Destructor
Option::~Option() {}

// Assignment Operator
Option& Option::operator=(const Option &other)
{
    if (this == &other)
    {
        return *this;
    }

    expiry = other.expiry;
    strike = other.strike;
    volatility = other.volatility;
    riskFreeRate = other.riskFreeRate;
    spot = other.spot;
    costOfCarry = other.costOfCarry;
    optType = other.optType;

    return *this;
}

// GETTERS
double Option::Expiry() const { return expiry; }                 // gets expiry value
double Option::Strike() const { return strike; }                 // gets strike value
double Option::Volatility() const { return volatility; }         // gets volatility value
double Option::RiskFreeRate() const { return riskFreeRate; }     // gets risk-free rate value
double Option::Spot() const { return spot; }                     // gets underlying Asset value
double Option::CostOfCarry() const { return costOfCarry; }       // gets cost of carry value
std::string Option::OptionType() const { return optType; }       // gets option type value


// SETTERS
void Option::SetExpiry(double val) { expiry = val; }                            // sets expiry value
void Option::SetStrike(double val) { strike = val; }                            // sets strike value
void Option::SetVolatility(double val) { volatility = val; }                    // sets volatility value
void Option::SetRiskFreeRate(double val) { riskFreeRate = val; }                // sets risk-free rate value    
void Option::SetSpot(double val) { spot = val; }                                // sets underlying Asset value
void Option::SetCostOfCarry(double val) { costOfCarry = val; }                  // sets cost of carry value           
void Option::SetOptionType(const std::string &Type) { optType = Type; }         // sets option type value



