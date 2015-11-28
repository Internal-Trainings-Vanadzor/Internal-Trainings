#ifndef SHAPE_H
#define SHAPE_H
#include "Geometry.h"

class Point;

class Shape {
	public:
		virtual bool contains(const Point& p) const = 0; //should be pure virtual
		virtual const Geometry::AreaType area() const = 0;
		virtual Geometry::ShapeType getType() const = 0;
		
};
#endif
