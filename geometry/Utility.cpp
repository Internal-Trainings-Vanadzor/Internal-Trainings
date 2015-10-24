#include "Utility.h"
#include <random>
#include <time.h>

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

Geometry::Point createPoint()
{
   return Geometry::Point(getRandomNumber(), getRandomNumber());
}

Geometry::Line createLine()
{
   return Geometry::Line(createPoint(), createPoint());
}

Geometry::Rect createRect()
{
   return Geometry::Rect(createPoint(), getRandomNumber(), getRandomNumber());
}

Geometry::Triangle createTriangle()
{
   return Geometry::Triangle(createPoint(), createPoint(), createPoint());
}

Geometry::Circle createCircle()
{
   return Geometry::Circle(Geometry::Point(), getRandomNumber());
}

}
