// Author: Kaiki Ikeda
// File: Exercise_2
// In this program we explored using boost library's tuple and initialized a tuple Person where it had specific attributes of NAME, AGE, and LENGTH.
// We made a function PrintPerson while using boost::get<T>(), which allowed us to retrieve the address of a specified value and print it out.
// With these, we made three people with specific types and tested the boost::get<T>() to see our attributes and even change the value of them.

#include <iostream>                            // include for standard input/output
#include <string>                              // include for std::string
#include <boost/tuple/tuple.hpp>               // include tuple from boost
#include <boost/tuple/tuple_io.hpp>            // include tuple input and output

typedef boost::tuple<std::string, int, double> Person;  // defining our typedef (tuple type Person with specific attributes of name, age, and length)

void PrintPerson(const Person &p)                                   // Function that will print all attributes of an object
{
    std::cout <<"Name: " << boost::get<0>(p) << std::endl           // print name
              << "Age: " << boost::get<1>(p) << std::endl           // print age
              << "Length: " << boost::get<2>(p) << std::endl        // print length   
    << std::endl;
}


int main()                                                          // main function to test our code
{
    Person kaiki = boost::make_tuple("Kaiki", 21, 6);               // create kaiki (type Person) with specific values
    Person sonia = boost::make_tuple("Sonia", 23, 5.4);             // create sonia (type Person) with specifc values
    Person random = boost::make_tuple("Random", 98, 5.9);           // create random (type Person) with specific values


    // call PrintPerson function to print contents of object
    PrintPerson(kaiki);                                             
    PrintPerson(sonia);
    PrintPerson(random);


    // setting new values for Kaiki's age and length
    boost::get<1>(kaiki) = 100;
    boost::get<2>(kaiki) = 99;

    // print out to see the new values of Kaiki set into place
    std::cout << "Printing the new values of Kaiki" << std::endl;
    PrintPerson(kaiki);

    return 0; // indicates a successfully ran program
}

