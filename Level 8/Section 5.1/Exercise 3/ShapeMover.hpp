// header file for our class ShapeMover

#ifndef SHAPEMOVER_HPP
#define SHAPEMOVER_HPP

#include "Line.hpp"                         // include Line header file
#include "Point.hpp"                        // include Point header file
#include "Circle.hpp"                       // include Circle header file
#include <boost/variant.hpp>                // include boost library's variant


// defining our class ShapeMover - inherits from static_visitor<void>
class ShapeMover : public boost::static_visitor<void>
{
private:
    double m_dx;        // member variable x
    double m_dy;        // member variable y

public:

    ShapeMover(double x, double y);                    // constructor              

    void operator()(Point &p) const;                   // () operator for Point
    void operator()(Line &l) const;                    // () operator for Line
    void operator()(Circle &c) const;                  // () operator for Circle
};


#endif    // SHAPEMOVER_HPP