#include "Rect.h"
#include "Point.h"
#include "Geometry.h"
using namespace Geometry;

bool Rect::contains(const Point& p) const
{
   return p.x() >= m_lowerLeft.x() && p.x() <= m_lowerLeft.x() + (CoordinateType)m_width  && 
          p.y() >= m_lowerLeft.y() && p.y() <= m_lowerLeft.y() + (CoordinateType)m_height;
}
