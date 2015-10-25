#include <random>
#include <time.h>
#include "Utility.h"
#include "Geometry.h"
#include "Point.h"
#include "Canvas.h"

namespace Utility {

namespace {
   Geometry::CoordinateType getRandomNumber()
   {
      static time_t t = time(0);
      unsigned int u_t(t);
      srand(u_t);
      u_t = rand() % 1000;
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
