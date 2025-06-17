#ifndef SDANDSE_HPP
#define SDANDSE_HPP

#include <cmath>
#include <vector>

double optionSD(const std::vector<double> &prices, double r, double T)
{
    double call_t = 0.0;
    double call_tsquared = 0.0;
    long NSim = prices.size();
    
    for (long i = 0; i < NSim; i++)
    {
        call_t += prices[i];
        call_tsquared += prices[i] * prices[i];
    }
    
    return sqrt((call_tsquared - (call_t*call_t)/NSim) / (NSim-1)) * exp(-r * T);
}

double optionSE(const std::vector<double> &prices, double r, double T)
{
    return optionSD(prices, r, T)/sqrt(prices.size());
}

#endif  // SDANDSE_HPP