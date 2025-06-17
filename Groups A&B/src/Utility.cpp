// Source file for Utility functions

#include "../include/Utility.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <boost/math/distributions/normal.hpp>

// standard normal cumulative distribution function
double N(double x)
{
    static boost::math::normal_distribution<> standardNormal(0.0, 1.0);    // Returns N(x), the cumulative standard normal distribution function       
    return boost::math::cdf(standardNormal, x);
}

// standard normal PDF
double n(double x)
{
    return (1.0 / sqrt(2.0 * M_PI)) * exp(-0.5 * x * x);
}

// Generate a mesh array [start, start + h, .. , end]
std::vector<double> meshArray(double start, double end, double h)
{
    std::vector<double> result;
    for (double x = start; x <= end; x += h)
    {
        result.push_back(x);
    }
    return result;
}

// Put-call parity to compute call price given put
double PutCallParityCall(double putPrice, double S, double K, double r, double T)
{
    return putPrice + S - K * std::exp(-r * T);
}

// Put-call parity to compute put given call
double PutCallParityPut(double callPrice, double S, double K, double r, double T)
{
    return callPrice - S + K * std::exp(-r * T);
}

bool CheckPutCallParity(double callPrice, double putPrice, double S, double K, double r, double T, double tolerance)
{
    double lhs = callPrice + K * std::exp(-r * T);
    double rhs = putPrice + S;

    return std::fabs(lhs - rhs) < tolerance;         // compute the absolute value of float and check if less than tolerance
}

// Compute the Perpetual American Call option with this function
double PerpetualCall(double K, double sig, double r, double b, double S)
{
    double sigmaSq = sig * sig;
    double fac = b / sigmaSq - 0.5;
    double y1 = 0.5 - b / sigmaSq + std::sqrt(std::pow(fac, 2) + 2 * r / sigmaSq);

    if (y1 <= 1.0)    // Error check for robustness
    {
        throw std::runtime_error("Invalid input: y1 must be greater than 1.");
    }

    return (K / (y1 - 1)) * std::pow(((y1 - 1) / y1) * (S / K), y1);
}

// Compute the perpetual American put option with this function
double PerpetualPut(double K, double sig, double r, double b, double S)
{
    double sigmaSq = sig * sig;
    double fac = b / sigmaSq - 0.5;
    double y2 = 0.5 - b / sigmaSq - std::sqrt(std::pow(fac, 2) + 2 * r / sigmaSq);

    if (y2 >= 0.0)
    {
        throw std::runtime_error("Invalid input: y2 must be less than 0.");
    }

    return (K / (1 - y2)) * std::pow(((y2 - 1) / y2) * (S / K), y2);
}



