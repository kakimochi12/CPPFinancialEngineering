// This Main.cpp file aims to compute option price of underlying
// values of S in the range 10-50. Similar to our assignment in Groups A & B
// but this time we print the output in excel
// Author: Kaiki Ikeda

#include "Header Files/EuropeanOption.hpp"
#include "Header Files/Utility.hpp"
#include "Header Files/ExcelDriverLite.hpp"

int main()
{

	{
		// Batch 1 test for Single Curve
		// Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13337, P = 5.84628).
		std::string optType = "C";
		double expiry = 0.25;
		double strike = 65.0;
		double volatility = 0.30;
		double riskFreeRate = 0.08;
		double spot = 60.0;
		double costOfCarry = 0.0;

		EuropeanOption opt1(optType, expiry, strike, volatility, riskFreeRate, spot, costOfCarry);

		std::vector<double> S1 = meshArray(10.0, 50.0, 1.0);
		std::vector<double> prices1;

		for (double s : S1)
		{
			opt1.SetSpot(s);
			prices1.push_back(opt1.Price());
		}

		printOneExcel(S1, prices1, "Batch 1 Option Prices", "S", "Price", "European Call");
	}

	{

		// Batch 2 test for two curve
		// Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96557, P = 7.96557).
		std::string optType = "C";
		double expiry = 1.0;
		double strike = 100.0;
		double volatility = 0.2;
		double riskFreeRate = 0.0;
		double spot = 100.0;
		double costOfCarry = 0.0;

		EuropeanOption opt2(optType, expiry, strike, volatility, riskFreeRate, spot, costOfCarry);

		std::vector<double> S2 = meshArray(10.0, 50.0, 1.0);
		std::vector<double> prices2;

		for (double s : S2)
		{
			opt2.SetSpot(s);
			prices2.push_back(opt2.Price());
		}

		printOneExcel(S2, prices2, "Batch 2 Option Prices", "S", "Price", "European Call");
	}

	return 0;

}