#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Shape.h"
#include "Geometry.h"
using namespace Geometry;

class Ellipse:public Shape {
    public:
	Ellipse (const Point& radiusOne, const Point& radiusTwo, const Point& center)
		:m_center(center)
		,m_radiusOne(radiusOne)
		,m_radiusTwo(radiusTwo)
	{} 

	bool contains(const Point& p) const; 
	const Geometry::AreaType area() const; 
	const Point& center() const {
		return m_center;
	};
	const Point& radiusOne() const {
		return m_radiusOne;
	}
	const Point& focusTow() const {
		return m_radiusTwo;
	}
	ShapeType getType() const
	{ return elipse; }

    private:	
	Point m_radiusOne;
	Point m_radiusTwo;
	Point m_center;
    };
#endif
