#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include "Geometry.h"

class Shape {
	public:
		virtual bool contains(const Point& p) const = 0; //should be pure virtual
		virtual const Geometry::AreaType area() const = 0;  
};
#endif