#define _USE_MATH_DEFINES
#include <cmath>
#include "Ellipse.h"
#include "Geometry.h"
using namespace Geometry;

const AreaType Ellipse::area() const
{
  return M_PI * ((m_radiusOne.x(), m_radiusOne.y(), m_center.x(), m_center.y()) *
          m_radiusTwo.x(), m_radiusTwo.y(), m_center.x(), m_center.y()); 
}


bool Ellipse::contains(const Point& p) const
{
//tbd
}

double distance ( const int &x1, const int &y1, const int &x2,const int &y2) {
	double dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return dist;
}


