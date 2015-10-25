#include <cmath>
#include "Point.h"

Point::Point (CoordinateType x, CoordinateType y)
    : m_x(x)
      , m_y(y)
{}

const CoordinateType& Point::x() const
   { 
      return m_x;
   }
 CoordinateType& Point::x()
   { 
      return m_x;
   }

 const CoordinateType& Point::y() const
   { 
      return m_y;
   }
 CoordinateType& Point::y()
   { 
      return m_y;
   }

 const AreaType Point::area() const
   {
      return 0;
   }

 bool Point::contains(const Point& p) const
   {
      return x() == p.x() && y() == p.y();
   }

DistanceType Point::distance(const Point& p) const
   {
      DistanceType dx = x() - p.x();
      DistanceType dy = y() - p.y();
      return sqrt(dx * dx + dy * dy);
   }

