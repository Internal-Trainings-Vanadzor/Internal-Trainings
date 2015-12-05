#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cmath>
#include <cassert>
namespace Geometry {

	typedef float CoordinateType;
	typedef double DistanceType;
	typedef double AreaType;
	typedef unsigned int SizeType;

	enum class ShapeType {
		rect = 0, triangle, circle, line, elipse
	};
}

#endif
