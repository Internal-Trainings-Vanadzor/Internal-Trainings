#ifndef GEOMETRY_CREATOR_HPP
#define GEOMETRY_CREATOR_HPP

#include "Geometry.h"
#include "Point.h"
#include "Canvas.h"
#include "Line.h"
#include "Rect.h"
#include "Triangle.h"
#include "Circle.h"

namespace Utility {

Point createPoint();
Line createLine();
Rect createRect();
Triangle createTriangle();
Circle createCircle();

}


#endif