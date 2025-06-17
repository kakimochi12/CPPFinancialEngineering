// Author: Kaiki Ikeda
// File: Exercise_4
// In this program we used the functions from Random library and created a discrete uniform
// random number generator for range (1, 6). We mapped key value pairs for each value's frequency and calculated the percentage
// of total ourcomes.

#include <iostream>
#include <boost/random.hpp>
#include <map>
 
int main()
{
    
    int number_trials;                                                    // Store integer for user input
    std::cout << "Input the number of trials: " << std::endl;             // Ask the user for input
    std::cin >> number_trials;                                            // input is stored

    std::map<int, long> statistics;   // structure to hold outcome + frequencies

    // throwing dice
    // Mersenne Twister
    boost::random::mt19937 myRng;

    // Set the seed
    myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

    // Uniform in range [1, 6]
    boost::random::uniform_int_distribution<int> six(1, 6);

    for (int i = 1; i <= number_trials; ++i)
    {
        int outcome;                      // current outcome
        outcome = six(myRng);             // generates a number 1-6

        statistics[outcome]++;            // add the count of random number
    }


    // Traverse the statistics map
    for (const auto& pair : statistics)
    {
        double percent_frequency = (static_cast<double>(pair.second) / number_trials) * 100;                    // Calculate percent frequency

        std::cout << "Trial " << pair.first << " has " << percent_frequency << "% outcomes" << std::endl;       // print out the percent frequency for each value
    }

    return 0; // indicates a successfully ran program
}