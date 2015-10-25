#include <cmath>
#include <limits>
#include "Triangle.h"
#include "Point.h"
#include "Geometry.h"

namespace Area{
    AreaType area(const Point& a, const Point& b, const Point& c)
    {
        return (AreaType)std::abs((c.x() - a.x()) * (b.y() - a.y()) - (c.y() - a.y()) * (b.x() - a.x())) / 2;
    }
}


const AreaType Triangle::area() const
{  
	return Area::area(m_a, m_b, m_c);
}

bool Triangle::contains(const Point& p) const
{
   return std::abs(area() - (Area::area(p, m_a, m_b) +
	     Area::area(p, m_a, m_c) + Area::area(p, m_b, m_c))) 
		 < 4 * std::numeric_limits<AreaType>::epsilon();
}
