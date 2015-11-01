#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.h"
#include "Geometry.h"

class Circle: public Shape {

public:
   Circle(const Point& c, DistanceType r)
      : m_center(c)
      , m_radius(r)
   {}

   const Geometry::AreaType area() const;
   bool contains(const Point& p) const;

private:
   Point m_center;
   DistanceType m_radius;

};
#endif
