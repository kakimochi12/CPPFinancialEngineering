// header file for functions that will test our batches

#ifndef TESTING_HPP
#define TESTING_HPP

// Test Batch 1-4 by calculating their Option prices
void TestBatch(int batchID, double T, double K, double sig, double r, double S);

// Spot Range pricing function for part C
void TestSpotRangePricing(double T, double K, double sig, double r, double b = -1.0);

// Test exact greeks (delta and gamma) for one option
void TestExactGreeks(double T, double K, double sig, double r, double S, double b, const std::string &type);

// Test numerical Greeks over a range of spot values
void TestExactDeltaOverSpotRange(double T, double K, double sig, double r, double b, const std::string& type);

// Test batch sensitivity calculations using exact Greeks
void TestExactSensitivityBatch();

// Test numerical approximations of Greeks using central difference
void TestNumericalGreeks(double T, double K, double sig, double r, double S, double b, const std::string& type, double h);

// Test numerical Greeks over a range of spot values
void TestNumericalGreeksOverSpot(double T, double K, double sig, double r, double b, const std::string &type, double h);

// Test batch sensitivity calculations
void TestSensitivityBatch(double h);

// Test exact price for given perpetual option input
void TestPerpetualPrice();

// Test exact American option pricing over a spot range
void TestPerpetualOverSpotRange();

// Test batch processing of perpetual American option pricing
void TestPerpetualBatch();

#endif   // TESTING_HPP