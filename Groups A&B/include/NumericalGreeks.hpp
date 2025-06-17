// Header file for our Delta and Gamme approximations

#ifndef NUMERICALGREEKS_HPP
#define NUMERICALGREEKS_HPP

#include "EuropeanOption.hpp"
#include <vector>

// Approximate delta using divided difference
double DeltaApprox(const EuropeanOption &opt, double h);

// Approximate gamme using divided difference
double GammaApprox(const EuropeanOption &opt, double h);

// Compute delta vector over a range of spot values
std::vector<double> DeltaOverSpotRange(const EuropeanOption &opt, double start, double end, double h, double step);

// Batch Delta OR gamma over parameter matrix
std::vector<double> SensitivityBatch(const std::vector<std::vector<double>> &paramMatrix,
                                     const std::vector<std::string> &types,
                                     const std::vector<std::string> &sensitivityType,
                                     double h);


#endif // NUMERICALGREEKS_HPP