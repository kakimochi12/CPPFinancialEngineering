// Author: Kaiki Ikeda
// File: Exercise_1
// This program aims to explore the features of the Standard Template Library containers. We first created a list and explore the first and back functions
// to access the first and lass elements, then we created a vector to see how we can use index operators and even make the vector grow. Lastly, we created a map
// with a key, value pair strings to doubles and proceededto access elements with the square bracket operator.

#include <iostream>
#include <list>         // for std::list
#include <vector>       // for std::vector
#include <map>          // for std::map

// #include <bits/stdc++.h> (includes all standard C++ libraries in one shot)


// using namespace std;  (Perhaps its good to use it but I figured its good practice to specify std:: in the code especially when I do big projects to avoid conflicting names)

int main()
{  
    // LIST 
    std::list<double> a_list;                                                                                       // create a list of doubles
    
    // practicing push_back function
    a_list.push_back(1);                    // append 1
    a_list.push_back(2);                    // append 2
    a_list.push_back(3);                    // append 3
    a_list.push_back(4);                    // append 4
    a_list.push_back(5);                    // append 5
    
    std::cout << "Testing the front() function: " << a_list.front() << std::endl;                                   // print the front value
    std::cout << "Testing the back() function: " << a_list.back() << std::endl;                                     // print the back value


    // VECTOR
    std::vector<double> a_vector = {9, 8, 7, 6};                                                                    // initialize a vector with doubles
    std::cout << "Testing the index operator by showing element at index 0: " << a_vector[0] << std::endl;          // print out value at index 0
    std::cout << "Testing the index operator by showing element at index 3: " << a_vector[3] << std::endl;          // print out value at index 3

    std::cout << "This is the original capacity of the vector: " << a_vector.capacity() << std::endl;               // print out the original capacity of the vector
    a_vector.reserve(10);                                                                                           // increase the capacity of vector to 10

    std::cout << "We made the vector grow to size: " << a_vector.capacity() << std::endl;                           // prints the new capacity

    // MAP
    std::map<std::string, double> a_map = {{"apple", 1.0}, {"orange", 2.0}, {"mango", 3.0}};                        // initializing a map with key, value pair
    std::cout << "Accessing element from map using sqaure bracket operator: " << a_map["apple"] << std::endl;       // printing value of key apple with bracket operator
    std::cout << "Accessing element from map using sqaure bracket operator: " << a_map["orange"] << std::endl;      // printing value of key orange with bracket operator
    std::cout << "Accessing element from map using sqaure bracket operator: " << a_map["mango"] << std::endl;       // printing value of key mango with bracket operator


    return 0; // indicates a successfully ran program
}