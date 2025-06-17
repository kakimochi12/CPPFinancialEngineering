// Header file for batch pricing
// description: computes option prices for a batch of parameter sets and option types
// parameter 1: paraMatrix each inner vector contains {T, K, sig, r, S, b}
// parameter 2: types will have the corresponding option types "C" or "P"

#ifndef BATCHPRICER_HPP
#define BATCHPRICER_HPP

#include <vector>
#include <string>

// Instead of computing one price per call, we can input vectors to output a vector of computed prices
std::vector<double> PriceOptionsBatch(const std::vector<std::vector<double>> &paramMatrix,
                                      const std::vector<std::string> &types);


#endif   // BATCHPRICER_HPP