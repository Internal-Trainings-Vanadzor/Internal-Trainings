#define _USE_MATH_DEFINES
#include <cmath>
#include "Ellipse.h"
#include "Geometry.h"
#include "Point.h"
using namespace Geometry;

const AreaType Ellipse::area() const
{
  	CoordinateType midX = getMidpointCoordinate((*m_focuseOne).x(), (*m_focuseTwo).x());
  	CoordinateType midY = getMidpointCoordinate((*m_focuseOne).y(), (*m_focuseTwo).y());
  	AreaType legs = distance(midX, midY, (*m_focuseOne).x(), (*m_focuseOne).y());
	AreaType distFocuseOne = distance((*m_point).x(), (*m_point).y(),  (*m_focuseOne).x(), (*m_focuseOne).y());
        AreaType distFocuseTow = distance((*m_point).x(), (*m_point).y(),  (*m_focuseTwo).x(), (*m_focuseTwo).y());
  	AreaType hypotenuse = getMiddle (distFocuseOne, distFocuseTow);  
  	AreaType m_smallRadius = sqrt(hypotenuse * hypotenuse - legs * legs); 
  	AreaType m_bigRadius = hypotenuse; 
  	return M_PI * m_bigRadius * m_smallRadius;
}


bool Ellipse::contains(Point* p) const
{
	AreaType distPoint = distance((*p).x(), (*p).y(), (*m_focuseOne).x(), (*m_focuseOne).y()) + 
		distance((*p).x(), (*p).y(), (*m_focuseTwo).x(), (*m_focuseTwo).y());
	AreaType distFocuseOne = distance((*m_point).x(), (*m_point).y(),  (*m_focuseOne).x(), (*m_focuseOne).y());
	AreaType distFocuseTow = distance((*m_point).x(), (*m_point).y(),  (*m_focuseTwo).x(), (*m_focuseTwo).y());
	AreaType distFocuse = distFocuseOne + distFocuseTow;
	if (distPoint == distFocuse) {
		return true;
	} else {
		return false;
	}
}

AreaType Ellipse::distance (const CoordinateType& x1, const CoordinateType& y1, const CoordinateType& x2,const CoordinateType& y2) const {
	AreaType dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return dist;
}

double Ellipse::getXCoordinatByLineLen(const CoordinateType& x, const double& l){
	return x + l*cos(0);	
}

double Ellipse::getiYCoordinatByLineLen(const CoordinateType& y, const double& l){
	return y + l*sin(0);	
}

CoordinateType Ellipse::getMidpointCoordinate(const CoordinateType& x1, const CoordinateType& x2) const {
	return (x1 + x2)/2.0;
}      

SizeType Ellipse::getMiddle(AreaType lineOne, AreaType lineTwo) const {
	return (lineOne + lineTwo)/2.0;
}   
