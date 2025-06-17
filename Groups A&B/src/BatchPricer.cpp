// Source file for our batch pricer function

#include "../include/BatchPricer.hpp"
#include "../include/EuropeanOption.hpp"
#include <stdexcept>


// Options Batch pricer that takes in vector parameter fileld with values for variables
std::vector<double> PriceOptionsBatch(const std::vector<std::vector<double>> &paramMatrix,
                                      const std::vector<std::string> &types)
{   
    // make sure vectors have matching sizes (robustness)
    if (paramMatrix.size() != types.size())
    {
        throw std::runtime_error("Mismatch: number of parameter sets does not match number of option types.");
    }

    std::vector<double> results;

    for (size_t i = 0; i < paramMatrix.size(); ++i)   // size_t is an unsigned int use for sizes and indices. I could use an int but big scripts might overflow.
    {
        const auto &p = paramMatrix[i];   // p = (T, K, sig, r, S, b)
        
        // Check if the parameter has the required variable
        if (p.size() != 6)
        {
            throw std::runtime_error("Each parameter row must contain exactly 6 values: {T, K, sig, r, S, b}");
        }
        const std::string &type = types[i];

        // European option initialization with parameters
        EuropeanOption opt(type, p[0], p[1], p[2], p[3], p[4], p[5]);

        // add the calculation of that option to results vector
        results.push_back(opt.Price());
    }
 
    return results;
}