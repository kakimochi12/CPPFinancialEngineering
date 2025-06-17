// source file for our testing functions

#include "../include/EuropeanOption.hpp"
#include "../include/NumericalGreeks.hpp"
#include "../include/PerpetualAmericanOption.hpp"
#include "../include/Utility.hpp"
#include "../include/Testing.hpp"
#include <cmath>
#include <iostream>
#include <vector>

// Test a single option pricing batch
void TestBatch(int batchID, double T, double K, double sig, double r, double S)
{
    double b = r;     // cost of carry for stock options

    EuropeanOption callOption("C", T, K, sig, r, S, b);      // initialize a call
    EuropeanOption putOption("P", T, K, sig, r, S, b);       // initialize a put

    double callPrice = callOption.Price();                   // calculate the call price
    double putPrice = putOption.Price();                     // calculate the put price


    // print batch number, call price, and put price
    std::cout << "==== BATCH " << batchID << " ====\n\n";
    std::cout << "Call Price: " << callPrice << "\n";
    std::cout << "Put Price: " << putPrice << "\n";

    // recalculate using put-call parity
    double parityCall = PutCallParityCall(putPrice, S, K, r, T);     // C = P + S - Ke^{-rT}
    double parityPut = PutCallParityPut(callPrice, S, K, r, T);      // P = C - S + Ke^{-rT}


    std::cout << "Call from Parity: " << parityCall << "\n";
    std::cout << "Put from Parity: " << parityPut << "\n";

    // check parity
    bool parityOK = CheckPutCallParity(callPrice, putPrice, S, K, r, T, 1e-5);
    std::cout << "Parity Check: " << (parityOK ? "PASS" : "FAIL") << "\n\n";
}

// Test pricing over a range of S
// T Expiry in years
// K Strike Price
// sig Volatility (standard dev.)
// r Risk Free Interest Rate
// b cost of carry = r
void TestSpotRangePricing(double T, double K, double sig, double r, double b)
{
    if (b < 0) b = r;  // default to r if b is not given
    std::cout << "==== PART C: Pricing Call options over Spot range ====\n";
    

    std::vector<double> spotRange = (meshArray(10, 50, 1));     // create a spot range using our utilities function
    std::vector<double> callPrices;                             // create a store for each spot's corresponding answer.

    for (double S : spotRange)                                                // iterate through spotRange
    {
        EuropeanOption callOption("C", T, K, sig, r, S, b);                   // plug in each value into callOption function for each iter
        double price = callOption.Price();                                    // call Price() to calculate Pricing
        callPrices.push_back(price);                                          // add answer to callPrices vector
        std::cout << "S: " << S << "     Call Price: " << price << "\n";      // print the contents
    }

    std::cout << "\n";
}

// ==== GREEKS EXERCISES ====

// A
void TestExactGreeks(double T, double K, double sig, double r, double S, double b, const std::string &type)
{
    // Initialize option with these parameters
    EuropeanOption opt(type, T, K, sig, r, S, b);  

    // check if call or put
    std::cout << "\n[Part A] Exact Greeks for " << (type == "C" ? "Call" : "Put") << ":\n";

    // calculate delta and gamma for option
    std::cout << "Delta: " << opt.Delta() << "\n";
    std::cout << "Gamma: " << opt.Gamma() << "\n";
}

// B
void TestExactDeltaOverSpotRange(double T, double K, double sig, double r, double b, const std::string &type)
{
    // using our meshArray function to create 10-50 with step 1.0
    std::vector<double> S_range = meshArray(10.0, 50.0, 1.0);

    // check if call or put
    std::cout << "\n[Part B] Exact Delta over Spot Range for " << (type == "C" ? "Call" : "Put") << ":\n";

    // go through the range
    for (double S : S_range)
    {
        EuropeanOption opt(type, T, K, sig, r, S, b);
        std::cout << "S = " << S << ", Delta = " << opt.Delta() << "\n";    // calculate delta for every value
    }
}

// C
void TestExactSensitivityBatch()
{

    // vector filled with parameters
    std::vector<std::vector<double>> params = {
        {0.25, 65.0, 0.30, 0.08, 60.0, 0.08},                // T, K, sig, r, S, b
        {1.0, 100.0, 0.2, 0.0, 100.0, 0.0},
        {1.0, 10.0, 0.50, 0.12, 5.0, 0.12},
        {30.0, 100.0, 0.30, 0.08, 100.0, 0.08}
    };

    // corresponding types for each parameter vector
    std::vector<std::string> types = {"C", "P", "C", "P"};   // change for exam?

    // corresponding sensitivities for parameter vector
    std::vector<std::string> sensitivities = {"Delta", "Gamma", "Delta", "Gamma"};   // change for exam?

    // Use sensitivty Batch function for our initialized results variable
    std::vector<double> results = SensitivityBatch(params, types, sensitivities, 0.01);

    std::cout << "\n[Part C] Exact Sensitivity Batch:\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        // print contents of our types, sensitivities, and results
        std::cout << "Option " << i + 1 << " (" << types[i] << ", " << sensitivities[i] << "): " << results[i] << "\n";
    }
}

// D
void TestNumericalGreeks(double T, double K, double sig, double r, double S, double b, const std::string &type, double h)
{
    // initialize european option with given parameters
    EuropeanOption opt(type, T, K, sig, r, S, b);
    std::cout << "\n[Part D.1] Numerical Greeks for " << (type == "C" ? "Call" : "Put") << ":\n";

    // approximate delta and gamma for this Option
    std::cout << "Delta (approx): " << DeltaApprox(opt, h) << "\n";
    std::cout << "Gamma (approx): " << GammaApprox(opt, h) << "\n";
}

void TestNumericalGreeksOverSpot(double T, double K, double sig, double r, double b, const std::string &type, double h)
{
    // create mesh array with range 10-50
    std::vector<double> S_range = meshArray(10.0, 50.0, 1.0);

    // check if call or put
    std::cout << "\n[Part D.2] Numerical Delta over Spot Range for " << (type == "C" ? "Call" : "Put") << ":\n";

    // go through the range
    for (double S : S_range)
    {
        // calculatye delta approx with S range
        EuropeanOption opt(type, T, K, sig, r, S, b);
        std::cout << "S = " << S << ", Delta (approx) = " << DeltaApprox(opt, h) << "\n";
    }
}

void TestSensitivityBatch(double h)
{
    // vector filled with parameters
    std::vector<std::vector<double>> params = {
        {0.25, 65.0, 0.30, 0.08, 60.0, 0.08},
        {1.0, 100.0, 0.2, 0.0, 100.0, 0.0},
        {1.0, 10.0, 0.50, 0.12, 5.0, 0.12},
        {30.0, 100.0, 0.30, 0.08, 100.0, 0.08}
    };

    // corresponding types
    std::vector<std::string> types = {"C", "P", "C", "P"};

    // corresponding sensitivities
    std::vector<std::string> sensitivities = {"Delta", "Gamma", "Delta", "Gamma"};

    // results store with SensitivityBatch function being performed
    std::vector<double> results = SensitivityBatch(params, types, sensitivities, h);

    std::cout << "\n[Part D.3] Numerical Sensitivity Batch:\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        // print out the contents
        std::cout << "Option " << i + 1 << " (" << types[i] << ", " << sensitivities[i] << "): " << results[i] << "\n";
    }
}

// ========== PERPETUAL AMERICAN OPTION TESTS ========
// B
void TestPerpetualPrice()
{
    // given test values from PDF
    double K = 100.0;              // change for exam?
    double sig = 0.1;              // change for exam?
    double r = 0.1;                // change for exam?
    double b = 0.02;               // change for exam?
    double S = 110.0;              // change for exam?

    double callPrice = PerpetualCall(K, sig, r, b, S);      // call PerpetualCall() from utilites
    double putPrice  = PerpetualPut(K, sig, r, b, S);       // call PerpetualPut() from utilities

    // print out calculations
    std::cout << "==== Perpetual American Option Test (Single Input) ====" << std::endl;
    std::cout << "Call Price: " << callPrice << " (Expected: 18.5035)" << std::endl;
    std::cout << "Put Price : " << putPrice  << " (Expected: 3.03106)" << std::endl;
    std::cout << std::endl;
}

// C
void TestPerpetualOverSpotRange()
{
    // reusing test values
    double K = 100.0;   // change for exam?
    double sig = 0.1;   // change for exam?
    double r = 0.1;     // change for exam?
    double b = 0.02;    // change for exam?
    // reusing meshArray function
    std::vector<double> spotRange = meshArray(10.0, 50.0, 1.0);   // change for exam?  meshArray(start, stop, step) stop inclusive

    std::cout << "==== Perpetual American Option Prices over Spot Range ====" << std::endl;
    for (double S : spotRange)
    {
        double call = PerpetualCall(K, sig, r, b, S);      // calculate call value with S range
        double put  = PerpetualPut(K, sig, r, b, S);       // calculate put value with S range
        std::cout << "S: " << S << "  Call: " << call << "  Put: " << put << std::endl;
    }
    std::cout << std::endl;
}

// D
void TestPerpetualBatch()
{
    std::cout << "==== PERPETUAL AMERICAN OPTION PRICING: BATCH TESTS ====\n";

    // Batch inputs: (K, sig, r, b, S)
    std::vector<std::vector<double>> paramMatrix = {
        {100.0, 0.1, 0.1, 0.02, 110.0},     // Batch 1       change for exam?
        {80.0, 0.25, 0.08, 0.04, 90.0},     // Batch 2       change for exam?
        {120.0, 0.2, 0.05, 0.01, 130.0},    // Batch 3       change for exam?
        {50.0, 0.15, 0.1, 0.02, 55.0}       // Batch 4       change for exam?
    };

    // corresponding types vector
    std::vector<std::string> types = {"C", "P", "C", "P"};    // change for exam?

    // iterate parameter matrix
    for (size_t i = 0; i < paramMatrix.size(); ++i)
    {
        double K = paramMatrix[i][0];
        double sig = paramMatrix[i][1];
        double r = paramMatrix[i][2];
        double b = paramMatrix[i][3];
        double S = paramMatrix[i][4];

        std::cout << "Batch " << i + 1 << " (" << types[i] << "):\n";

        // Exception Handling for robustness
        try
        {
            // calculation if its a call
            if (types[i] == "C")
            {
                double price = PerpetualCall(K, sig, r, b, S);
                std::cout << "Perpetual Call Price = " << price << "\n\n";
            }

            // calculation if its a put
            else if (types[i] == "P")
            {
                double y1 = 0.5 - (b / (sig * sig)) + std::sqrt(
                    std::pow((b / (sig * sig)) - 0.5, 2) + (2.0 * r) / (sig * sig));
                
                // check if y1 is valid
                if (y1 <= 1.0)
                {
                    std::cout << "Invalid input: y1 = " << y1 << " <= 1. Skipping Put.\n\n";
                    continue;
                }

                double price = PerpetualPut(K, sig, r, b, S);
                std::cout << "Perpetual Put Price = " << price << "\n\n";
            }
            else
            {
                std::cout << "Invalid option type.\n";
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "Error computing price: " << e.what() << "\n\n";
        }
        
    }
}

