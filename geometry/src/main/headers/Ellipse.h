#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Shape.h"
#include "Point.h"
#include "Geometry.h"
using namespace Geometry;

class Ellipse:public Shape {
    public:
	Ellipse (const Point& focuseOne, const Point& focuseTwo, const Point& point)
		:m_point(point)
		,m_focuseTwo(focuseOne)
		,m_focuseOne(focuseTwo)
	{} 

	bool contains(const Point& p) const; 
	const Geometry::AreaType area() const; 
	const Point& getPoint() const {
		return m_point;
	};
	const Point& focuseOne() const {
		return m_focuseTwo;
	};
	const Point& focusTow() const {
		return m_focuseOne;
	};
	Geometry::ShapeType getType() const
	{ 
		return Geometry::ShapeType::elipse; 
	};
    private:	
 	CoordinateType getMidpointCoordinate(const CoordinateType& x1, const CoordinateType& x2) const;	
 	SizeType getMiddle(AreaType lineOne, AreaType lineTwo) const;	
	AreaType distance (const CoordinateType& x1, const CoordinateType& y1, const CoordinateType& x2,const CoordinateType& y2) const;
	double getXCoordinatByLineLen(const CoordinateType& x, const double& l);
	double getiYCoordinatByLineLen(const CoordinateType& y, const double& l);

	Point m_focuseTwo;
	Point m_focuseOne;
	Point point;
	AreaType m_bigRadius;
	AreaType m_smallRadius;
	
	Point m_point;
};
#endif
