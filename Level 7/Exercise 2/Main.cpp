// Author: Kaiki Ikeda
// File: Exercise_2
// In this program we created Sum functions utilizing the STL const_iterators to Sum or container types. I used these iterators to go through
// the generic containers and do range sums or total sums. I also made separate functions for maps because they operate a little differently with their
// key, value pairs.

#include "Sum.hpp"
#include <iostream>
#include <iterator>

int main()
{
    // initializing our containers
    std::vector<double> a_vector = {1.0, 2.0, 3.0};
    std::list<double> a_list = {4.0, 5.0, 6.0};
    std::map<int, double> a_map = {{1, 10.5}, {2, 20.3}, {3, 15.2}};

    // Full container sum for each
    std::cout << "The sum of our vector is: " << Sum(a_vector) << std::endl;                            // total sum of vector
    std::cout << "The sum of our list is: " << Sum(a_list) << std::endl;                                // total sum of list
    std::cout << "The sum of our map is: " << Sum<int, double>(a_map) << std::endl;                     // total sum of map

    // Sum within a given range
    std::cout << "Range sum for vector should be 3: " << Sum(a_vector.begin(), a_vector.begin()+2) << std::endl;                // range sum for vector
    std::cout << "Range sum for list should be 15: " << Sum(a_list.begin(), a_list.end()) << std::endl;                         // Notes to look back on: (cannot do + 2 to lists bc bidirectional.. used std::next() if you want to pick an end range)
    std::cout << "Range sum for map should be 46 : " << Sum<int, double>(a_map.begin(), a_map.end());                           // range sum for values

    return 0; // indicates a successfully ran program
}