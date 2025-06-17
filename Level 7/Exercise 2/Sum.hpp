// Header file for our various Sum() functions

#ifndef SUM_HPP
#define SUM_HPP

#include <vector>         // allow use std::vector
#include <list>           // allow use std::list
#include <map>            // allow use std::map
#include <iterator>       // allow use std::iterator

// Sum for generic containers (Vector, List, etc.)
template <typename T>
double Sum(const T& container)
{
    double sum = 0.0;                                                   // double sum store

    typename T::const_iterator it = container.begin();                  // set beginning iterator
    typename T::const_iterator end = container.end();                   // set end iterator

    for (; it != end; ++it)                                             // loop through left to right
    {
        sum += *it;                                                     // keep adding each value
    }

    return sum;                                                         // return sum
}

// Sum for map containers
template <typename K, typename V>                                       // Template for key, value pair (maps)
double Sum(const std::map<K, V>& container)                             // Sum for map
{
    double sum = 0.0;                                                     // double sum store

    typename std::map<K, V>::const_iterator it = container.begin();     // set const iterator for beginning
    typename std::map<K, V>::const_iterator end = container.end();      // set const iterator for end

    for (; it != end; ++it)                                             // loop left to right
    {
        sum += it->second;                                              // sum up the values
    }

    return sum;                                                         // return sum
}

// Sum between two indexes for generic containers
template <typename Iter>
double Sum(Iter start, Iter end)
{
    double sum = 0.0;                                                   // double sum store
    for (; start != end; ++start)                                       // iterate from start index until end index
    {
        sum += *start;                                                  // keep adding each element
    }

    return sum;                                                         // return sum
}

// sum between indexes for MAP container
template <typename K, typename V>                                                
double Sum(typename std::map<K, V>::const_iterator start, typename std::map<K, V>::const_iterator end)
{
    double sum = 0.0;                                                   // double sum store
    for (; start != end; ++start)                                       // iterate from start to end
    {
        sum += start->second;                                           // keep adding values in (key, value) pair
    }

    return sum;                                                         // return sum
}

#endif // SUM_HPP