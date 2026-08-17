// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"

namespace BS // Black Scholes
{
	// CHANGE VALUES FOR EXAM? ========================================
	double sig = 0.35;
	double K = 70;
	double T = 0.65;
	double r = 6.5;
	double D = 0.0; // aka q (dividends in percent decimal)

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		// Put
		return K *exp(-r * t);
	}

	double myBCR (double t)
	{
			
		// Put
		return 0.0; // P
	}

	double myIC (double x)
	{ // Payoff 
	
		// Put
		return max(K - x, 0.0);
	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J = static_cast<int>(300); int N = 300000-1; // k = O(h^2) !!!!!!!!!    EXAM========================
						//  (5*BS::K)       if NaN increase N or decrease T        N can be 4 * J * J 
	// increase J by 100 each time for better accuracy

	double Smax = 5*BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();

	// After solving PDE
	cout << "Finished\n";
	
	// Extract numerical price at S = 60
	double targetS = 70;                             // Make this the same as K EXAM=============================================================

	// Find closest grid to S = 60
	auto idx = std::distance(fdir.xarr.begin(), std::min_element(
		fdir.xarr.begin(), fdir.xarr.end(),
		[=](double a, double b) {
			return abs(a - targetS) < abs(b - targetS);
		}));

	double numerical = fdir.current()[idx];
	cout << "Numerical FDM price at S = " << targetS << " is " << numerical << endl;

	// Have you Excel installed (ExcelImports.cpp)
	printOneExcel(fdir.xarr, fdir.current(), string("Value"));

	return 0;
}
