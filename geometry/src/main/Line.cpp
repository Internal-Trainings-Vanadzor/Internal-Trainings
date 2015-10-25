#include "Line.h"
#include "Point.h"
#include "Geometry.h"
using namespace Geometry;

bool Line::contains(const Point& p) const
{
   CoordinateType pdx = p.x() - start().x();
   CoordinateType pdy = p.y() - start().y();
   CoordinateType ldx = start().x() - end().x();
   CoordinateType ldy = start().y() - end().y();
   return pdx * ldy == pdy * ldy;
}