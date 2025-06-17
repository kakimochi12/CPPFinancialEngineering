// Author: Kaiki Ikeda
// File: Exercise_5
// we experimented the exponential and poisson distribuitions.
// specifically the file "TestNormalDistribution.cpp" file was modified
// to work with exponential distribution instead of normal and Poisson instead of gamma.

// TestNormal.cpp
//
// First program test the Boost statistics library.
//
// Look at the Normal distribution because it is important.
// And gamma distribution
//
// 2008-6-27 DD initial code
// 2011-11-9 DD for QN course
//
// (C) Datasim Education BV 2009-2011
//

#include <boost/math/distributions/exponential.hpp>	// for exponential distributions
#include <boost/math/distributions/poisson.hpp>		// for poisson distributions
#include <boost/math/distributions.hpp> 			// For non-member functions of distributions

#include <vector>           // for std::vector
#include <iostream>			// for input/output
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	exponential_distribution<> myExponential(0.5); // creates exponential distribution object w/ param 0.5 lambda
	cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myExponential, x) << endl;		// probability density function
	cout << "cdf: " << cdf(myExponential, x) << endl;		// cumulative distribution function

	// another exponential distribution (how likely something happens PER unit time)
	exponential_distribution<float> myExponential2; 
	cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << endl;
	
	cout << "pdf: " << pdf(myExponential2, x) << endl;    // calculate pdf
	cout << "cdf: " << cdf(myExponential2, x) << endl;    // calculate cdf

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***exponential distribution: \n";								
	cout << "mean: " << mean(myExponential) << endl;								// mean for exponential_distribution
	cout << "variance: " << variance(myExponential) << endl;						// variance for exponential_distribution
	cout << "median: " << median(myExponential) << endl;							// median for exponential_distribution
	cout << "mode: " << mode(myExponential) << endl;								// mode for exponential_distribution
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;			// excess kurtosis for exponential_distribution
	cout << "kurtosis: " << kurtosis(myExponential) << endl;						// kurtosis for exponential_distribution
	cout << "characteristic function: " << chf(myExponential, x) << endl;			// char function for exponential_distribution
	cout << "hazard: " << hazard(myExponential, x) << endl;							// hazard for exponential_distribution

	// Poisson distribution
	double poissonmean = 3.0;         					// set mean to 3.0
	poisson_distribution<> myPoisson(poissonmean);		// (discrete distribution that gives probability of a number of events within interval of time or space)

	cout << "\n***poisson distribution: \n" << endl;    	
	cout << "mean: " << mean(myPoisson) <<  endl;			// mean for poisson_distribution
	cout << "variance: " << variance(myPoisson) << endl;	// variance for poisson distribution
	cout << "pdf and cdf values for range [0, 20]:\n";		

	vector<double> pdflist;					// initialize pdf list
	vector<double> cdflist;					// initialize cdf list

	int maxVal = 20;						
	for (int j = 0; j <= maxVal; ++j)				// loop until 20
	{
		pdflist.push_back(pdf(myPoisson, j));		// append pdf to pdflist
		cdflist.push_back(cdf(myPoisson, j));		// append cdf to cdflist
	}

	// print the contents of our pdf and cdf list
	for (int j = 0; j <= maxVal; ++j)
	{
		cout << "x = " << j << ": pdf = " << pdflist[j] << ", cdf = " << cdflist[j] << endl;
	}

	return 0;  // indicates a successfully ran program
}