#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cmath>
#include <cassert>
#include "Point.h"
namespace Geometry {

	typedef int CoordinateType;
	typedef double DistanceType;
	typedef double AreaType;
	typedef unsigned int SizeType;
	AreaType area(const Point& a, const Point& b, const Point& c)
    {
      return (AreaType)abs((c.x() - a.x()) * (b.y() - a.y()) - (c.y() - a.y()) * (b.x() - a.x())) / 2;
    }

}

#endif