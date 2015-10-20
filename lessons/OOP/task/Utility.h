#ifndef GEOMETRY_CREATOR_HPP
#define GEOMETRY_CREATOR_HPP

#include "Geometry.h"

namespace Utility {

Geometry::Point createPoint();
Geometry::Line createLine();
Geometry::Rect createRect();
Geometry::Triangle createTriangle();
Geometry::Circle createCircle();

}


#endif