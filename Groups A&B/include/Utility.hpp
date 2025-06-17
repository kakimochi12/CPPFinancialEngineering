// Header file for Utility functions

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>

// Cumulative normal distribution function
double N(double x);

// Standard normal PDF
double n(double x);

// Generate a mesh array [start, start + h, ... , end]
std::vector<double> meshArray(double start, double end, double h);

// Put-Call Parity functions
double PutCallParityCall(double putPrice, double S, double K, double r, double T);
double PutCallParityPut(double callPrice, double S, double K, double r, double T);

// Check if the given set of prices meets the put-call parity
bool CheckPutCallParity(double callPrice, double putPrice, double S, double K, double r, double T, double tolerance = 1e-5);

// pricing a perpetual american call option
double PerpetualCall(double K, double sig, double r, double b, double S);

// pricing a perpetual american put option
double PerpetualPut(double K, double sig, double r, double b, double S);

#endif  // UTILITY_HPP