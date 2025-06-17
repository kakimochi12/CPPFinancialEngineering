// Source file for Delta and Gamme approximations

#include "../include/NumericalGreeks.hpp"
#include <cmath>
#include <stdexcept>

// Approximate delta using divided difference
double DeltaApprox(const EuropeanOption &opt, double h)
{
    EuropeanOption opt_up = opt;                // store for increased spot
    EuropeanOption opt_down = opt;              // store for decreased spot

    opt_up.SetSpot(opt_up.Spot() + h);          // calculate increased spot
    opt_down.SetSpot(opt_down.Spot() - h);      // calculate decreased spot

    double price_up = opt_up.Price();           // calculate simulation of increase
    double price_down = opt_down.Price();       // calculate simulation of decrease 

    return (price_up - price_down) / (2.0 * h);     // compute output
}

// Approximate gamme using divided difference
double GammaApprox(const EuropeanOption &opt, double h)
{
    EuropeanOption opt_up = opt;                // store for increase spot
    EuropeanOption opt_down = opt;              // store for decrease spot
    EuropeanOption opt_mid = opt;               // store for unchanged spot 

    opt_up.SetSpot(opt_up.Spot() + h);          // add changes to spot
    opt_down.SetSpot(opt_down.Spot() - h);      // subtract changes to spot
    opt_mid.SetSpot(opt_mid.Spot());            // unchanged spot

    // compute different spots
    double price_up = opt_up.Price();           
    double price_down = opt_down.Price();
    double price_mid = opt_mid.Price();

    return (price_up + 2.0 * price_mid + price_down) / (h * h);    // output computation
}

// Compute delta vector over a range of spot values
std::vector<double> DeltaOverSpotRange(const EuropeanOption &opt, double start, double end, double h, double step)
{
    std::vector<double> deltas;                 // store all computed deltas

    for (double S = start; S <= end; S += step)     // loop through delta range
    {
        EuropeanOption modifiedOpt = opt;
        modifiedOpt.SetSpot(S);    // Set current spot in modified copy

        double delta = DeltaApprox(modifiedOpt, h);
        deltas.push_back(delta);
    }

    return deltas;      // return vector of computed deltas
}

// Batch Delta OR gamma over parameter matrix
std::vector<double> SensitivityBatch(const std::vector<std::vector<double>> &paramMatrix,
                                     const std::vector<std::string> &types,
                                     const std::vector<std::string> &sensitivityType,
                                     double h)
{
    // check if vectors have valid sizes
    if (paramMatrix.size() != types.size() || paramMatrix.size() != sensitivityType.size())
    {
        throw std::runtime_error("Mismatch in number of parameters, types or sensitivities.");
    }    

    // initialize results store
    std::vector<double> results;

    // loop through parameter matrix
    for (size_t i = 0; i < paramMatrix.size(); ++i)
    {
        const auto &p = paramMatrix[i];  // Expected params (T, K, sig, r, S, b)

        // check if not enough parameters provided
        if (p.size() != 6)
        {
            throw std::runtime_error("Each parameter row must have exactly six values for variables T, K, sig, r, S, b");
        }

        // initialize european option with current parameters
        EuropeanOption opt(types[i], p[0], p[1], p[2], p[3], p[4], p[5]);

        // if Delta.. calculate delta approximation and add it to our results
        if (sensitivityType[i] == "Delta")
        {
            results.push_back(DeltaApprox(opt, h));
        }
        
        // if gamma... calculate gamma approximation and add it to our results
        else if (sensitivityType[i] == "Gamma")
        {
            results.push_back(GammaApprox(opt, h));
        }
        
        // invalid sensitivity type
        else
        {
            throw std::runtime_error("Invalid sensitivity type detected: " + sensitivityType[i]);
        }
    }

    return results;
}



