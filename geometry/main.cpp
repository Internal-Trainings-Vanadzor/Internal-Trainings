#include "Geometry.h"
#include "StatisticalPainter.h"
#include "Utility.h"

#include <iostream>
#include <vector>

int main()
{

   std::vector<Geometry::Rect> rects;

   rects.push_back(Utility::createRect());
   rects.push_back(Utility::createRect());
   rects.push_back(Utility::createRect());
   rects.push_back(Utility::createRect());
   rects.push_back(Utility::createRect());

   Painter::StatisticalPainter p;

   for (size_t i = 0; i < rects.size(); ++i)
   {
      const Geometry::Rect& r = rects[i];
      std::cout << r.area() << std::endl;
      p.drawRect(r.lowerLeft().x(), r.lowerLeft().y(), r.width(), r.height());
   }

   std::cout << "----------------------------------------------------" << std::endl;

   std::vector<Geometry::Triangle> triangles;

   triangles.push_back(Utility::createTriangle());
   triangles.push_back(Utility::createTriangle());
   triangles.push_back(Utility::createTriangle());
   triangles.push_back(Utility::createTriangle());
   triangles.push_back(Utility::createTriangle());

   for (size_t i = 0; i < triangles.size(); ++i)
   {
      Geometry::Triangle& t = triangles[i];
      std::cout << t.area() << std::endl;
      p.drawTriangle(t.a().x(), t.a().y(), t.b().x(), t.b().y(), t.c().x(), t.c().y());
   }

   return 0;
}