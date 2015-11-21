#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"
#include "Geometry.h"
using namespace Geometry;

const AreaType Circle::area() const
{
   return M_PI * m_radius * m_radius / 2;
}
bool Circle::contains(const Point& p) const
{
    DistanceType dx = m_center.x() - p.x();
    DistanceType dy = m_center.y() - p.y();
    return dx * dx + dy * dy < m_radius * m_radius;
}
const DistanceType& Circle::radius() const
{
    return m_radius;
}
DistanceType& Circle::radius()
{
    return m_radius;
}
const Point& Circle::center() const
{
    return m_center;
}
Point& Circle::width()
{
    return m_center;
}
