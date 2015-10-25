#include <cmath>
#include <limits>
#include "Triangle.h"
#include "Point.h"
#include "Geometry.h"
using namespace Geometry;


const AreaType Triangle::area() const
{  
	return Geometry::area(m_a, m_b, m_c);
  // return (AreaType)abs((m_c.x() - m_a.x()) * (m_b.y() - m_a.y())
//		   - (m_c.y() - m_a.y()) * (m_b.x() - m_a.x())) / 2;;
}

bool Triangle::contains(const Point& p) const
{
   return abs(area() - (Geometry::area(p, m_a, m_b) +
	     Geometry::area(p, m_a, m_c) + Geometry::area(p, m_b, m_c))) 
		 < 4 * std::numeric_limits<AreaType>::epsilon();
}