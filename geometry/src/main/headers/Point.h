#ifndef POINT_H
#define POINT_H

#include "Geometry.h"
using namespace Geometry;

class Point{

public:
    Point (CoordinateType x = 0, CoordinateType y = 0 );
    const CoordinateType& x() const;
    CoordinateType& x();
    const CoordinateType& y() const;
    CoordinateType& y();
    const AreaType area() const;
    bool contains(const Point& p) const;
    DistanceType distance(const Point&) const;

private:
   CoordinateType m_x;
   CoordinateType m_y;

};
#endif
