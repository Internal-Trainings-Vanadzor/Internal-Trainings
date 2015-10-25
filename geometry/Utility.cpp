#include <random>
#include <time.h>
#include "Utility.h"
#include "Geometry.h"
#include "Point.h"
#include "Canvas.h"
#include "Line.h"
#include "Rect.h"
#include "Triangle.h"
#include "Circle.h"

namespace Utility {

namespace {
   Geometry::CoordinateType getRandomNumber()
   {
      static time_t t = time(0);
      srand(unsigned int(t));
      t = rand() % 1000;
      return rand() % 1000;
   }
}

Point createPoint()
{
   return Point(getRandomNumber(), getRandomNumber());
}

Line createLine()
{
   return Line(createPoint(), createPoint());
}

Rect createRect()
{
   return Rect(createPoint(), getRandomNumber(), getRandomNumber());
}

Triangle createTriangle()
{

	return Triangle(createPoint(), createPoint(), createPoint());
}

Circle createCircle()
{
   return Circle(Point(), getRandomNumber());
}

}
