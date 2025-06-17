// This is a header file for our skeleton class Option

#ifndef OPTION_HPP
#define OPTION_HPP

#include <string>

class Option
{
protected: // allow derived classes to access these

    // Option Parameters
    double expiry;             // Time to Expiry
    double strike;             // Strike Price
    double volatility;         // volatility
    double riskFreeRate;       // risk-free rate
    double spot;               // Underlying Stock Price
    double costOfCarry;        // cost of carry
    std::string optType;       // Takes "C" for Call and "P" for Put

public:

    Option();                                   // Default Constructor
    Option(const std::string &optType,          // Parameterized Constructor
        double expiry, 
        double strike,
        double volatility,
        double riskFreeRate,
        double spot,
        double costOfCarry = 0.0);

    Option(const Option &other);                // Copy Constructor
    virtual ~Option();                          // Virtual Destructor

    Option& operator=(const Option &other);     // Assignment Operator

    // GETTERS
    double Expiry() const;                    // get expiry value
    double Strike() const;                    // get strike value
    double Volatility() const;                // get volatility
    double RiskFreeRate() const;              // get risk free rate
    double Spot() const;                      // get spot value
    double CostOfCarry() const;               // get cost of carry
    std::string OptionType() const;           // get Option type

    // SETTERS
    void SetExpiry(double val);                         // set expiry value
    void SetStrike(double val);                         // set strike value
    void SetVolatility(double val);                     // set volaitlity value
    void SetRiskFreeRate(double val);                   // set risk free rate
    void SetSpot(double val);                           // set spot value
    void SetCostOfCarry(double val);                    // set cost of carry value
    void SetOptionType(const std::string &Type);        // set option type value

    // Abstract pricing function
    virtual double Price() const = 0;    // compute option price (to be overridden)
};

#endif    // OPTION_HPP