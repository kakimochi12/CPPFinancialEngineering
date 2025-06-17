// Source file for ShapeMover class

#include "ShapeMover.hpp"

ShapeMover::ShapeMover(double x, double y) : m_dx(x), m_dy(y)
{
    // constructor
}

// Operator () for Point object
void ShapeMover::operator()(Point &p) const
{
    p.X(p.X() + m_dx); 
    p.Y(p.Y() + m_dy);
}

//  Operator () for Line object
void ShapeMover::operator()(Line &l) const
{
    Point point_1 = l.Start();      // Get first point of Line
    Point point_2 = l.End();        // Get end point of Line

    point_1.X(point_1.X() + m_dx); point_1.Y(point_1.Y() + m_dy);   // shift start point
    point_2.X(point_2.X() + m_dx); point_2.Y(point_2.Y() + m_dy);   // shift end point

    l.Start(point_1);               // assign new shift to first point
    l.End(point_2);                 // assign new shift to last point
}

// Operator () for Circle object
void ShapeMover::operator()(Circle &c) const
{
    Point point_1 = c.CentrePoint();                   // get the center

    point_1.X(point_1.X() + m_dx);                     // add change to x
    point_1.Y(point_1.Y() + m_dy);                     // add change to y

    c.CentrePoint(point_1);                            // apply modified centre to the circle
}