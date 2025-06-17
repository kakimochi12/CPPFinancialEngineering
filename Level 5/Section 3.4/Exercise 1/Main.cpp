// Author: Kaiki Ikeda
// File: Exercise_1
// This program aims to test how the colon syntax improves our code. We initially test it by creating Line object without a colon syntax in our Point file
// and we can see how many constructors and destructors are called behind the scenes. After utilizing colon syntax, we can see a significant difference in code efficiency.

#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>


int main()
{
    Line l; 
    // PART ONE: I created 4 Point objects consisting of 2 default, 2 temporary assignment. There were also 4 destructions for the 2 temporaries and 2 members.
    //              
    //          When Line is created, its member Point objects are default constructed before the constructor body executes,
    //          Then, in the body of the constructor point_one = Point(0.0, 0.0) triggers a temporary point creation, which calls
    //          the coordinate constructor. Those temporary point objects are destroyed after the assignment. When the Line object goes out of scope
    //          point_one and point_two destructor destroys them.

    // PART TWO: it shows two constructors and two destructors once l goes out of scope ----- the number of point constructor, destructor and assignment calls is less than before
    //          
    //          Line l; triggers the default constructor of line  and in line's member initializer list, we constructed with colon syntax
    //          Therefore it calls points coord constructor twice and both members are destroyed with the destructor once l ges out of scope.
    //
    //          Without the colon syntax, both point_one and point_two would be default constructed and then the assignment operator gets called on each
    //          Thus, leading to more constructor and destructor calls ===> slower PERFORMANCE.

    return 0;
}