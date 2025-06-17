// Author: Kaiki Ikeda
// File: Exercise_3
// This program experiments with implicit and explicit constructors in C++. 
// Specifically, we explore how a constructor that accepts a single argument (double)
// can act as an implicit conversion operator — which allows comparisons like Point == double to compile.
// We then make the constructor `explicit` to prevent unintended conversions, causing the same code to fail compilation.
// This demonstrates the importance of controlling implicit behavior in C++ for clarity and safety.

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>

int main()
{
    // Create a Point using coordinates (1.0, 1.0)
    Point p(1.0, 1.0);

    // -- IMPLICIT CONVERSION EXAMPLE --
    // When the Point(double) constructor is not marked as explicit,
    // C++ sees `p == 1.0` and tries to resolve it using the operator==(const Point&).
    // To do this, it automatically (and implicitly) converts `1.0` into `Point(1.0, 1.0)`
    // using the single-argument constructor and the comparison succeeds.

    // -- EXPLICIT CONSTRUCTOR EXAMPLE --
    // Once we mark the constructor as `explicit`, C++ no longer allows implicit conversion.
    // Now `p == 1.0` fails to compile, because `1.0` cannot be automatically converted to a Point.
    // The only way to compare now is with an explicit cast: `p == Point(1.0)`.

    if (p == (Point)1.0)
        std::cout << "Equal!" << std::endl;
    else
        std::cout << "Not equal" << std::endl;

    return 0;
}
