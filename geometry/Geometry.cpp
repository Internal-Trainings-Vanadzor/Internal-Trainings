#include "Geometry.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>

namespace Geometry {

//Point ------------------------------------------------------------------------------
DistanceType Point::distance(const Point& p) const
{
    DistanceType dx = x() - p.x();
    DistanceType dy = y() - p.y();
    return sqrt(dx * dx + dy * dy);
}

//Line
bool Line::contains(const Point& p) const
{
   CoordinateType pdx = p.x() - start().x();
   CoordinateType pdy = p.y() - start().y();
   CoordinateType ldx = start().x() - end().x();
   CoordinateType ldy = start().y() - end().y();
   return pdx * ldy == pdy * ldy;
}

//Rect
bool Rect::contains(const Point& p) const
{
   return p.x() >= m_lowerLeft.x() && p.x() <= m_lowerLeft.x() + (CoordinateType)m_width  && 
          p.y() >= m_lowerLeft.y() && p.y() <= m_lowerLeft.y() + (CoordinateType)m_height;
}

//Triangle
namespace {
   AreaType area(const Point& a, const Point& b, const Point& c)
   {
      return (AreaType)abs((c.x() - a.x()) * (b.y() - a.y()) - (c.y() - a.y()) * (b.x() - a.x())) / 2;
   }
}

AreaType Triangle::area() const
{
   return Geometry::area(m_a, m_b, m_c);
}

bool Triangle::contains(const Point& p) const
{
   return abs(area() - (Geometry::area(p, m_a, m_b) + Geometry::area(p, m_a, m_c) + Geometry::area(p, m_b, m_c))) < 4 * std::numeric_limits<AreaType>::epsilon();
}

AreaType Circle::area() const
{
   return M_PI * m_radius * m_radius / 2;
}

bool Circle::contains(const Point& p) const
{
    DistanceType dx = m_center.x() - p.x();
    DistanceType dy = m_center.y() - p.y();
    return dx * dx + dy * dy < m_radius * m_radius;
}

}