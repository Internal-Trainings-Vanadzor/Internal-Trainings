#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include "Geometry.h"

enum COLOR {WHITE, BLACK, RED};

class Point:public Shape {

public:
	Point (CoordinateType x = 0, CoordinateType y = 0, COLOR color = WHITE);
    const CoordinateType& x() const;
    CoordinateType& x();
    const CoordinateType& y() const;
    CoordinateType& y();
    const Geometry::AreaType area() const;
    bool contains(const Point& p) const;
    DistanceType distance(const Point&) const;

private:
   CoordinateType m_x;
   CoordinateType m_y;
   COLOR m_color;

};
#endif