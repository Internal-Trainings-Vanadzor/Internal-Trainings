#include "StatisticalPainter.h"

#include <iostream>

namespace STPainter {

void StatisticalPainter::drawPoint(int x, int y) const
{
   std::cout << "drawPoint " << "px = " << x << " py = " << y << std::endl;
}

void StatisticalPainter::drawLine(int sx, int sy, int ex, int ey) const
{
   std::cout << "drawLine from " << " sx = " << sx << " sy = " << sy << " to ex = " << ex << " ey = " << ey << std::endl;
}

void StatisticalPainter::drawRect(int llx, int lly, unsigned int w, unsigned int h) const
{
   std::cout << "drawRect lower left " << " x = " << llx << " y = " << lly << "; width = " << w << " height = " << h << std::endl;
}

void StatisticalPainter::drawTriangle(int ax, int ay, int bx, int by, int cx, int cy) const
{
   std::cout << "drawTriangle " << " ax = " << ax << " ay = " << ay << " bx = " << bx << " by = "  << by << " cx = " << cx << " cy = " << cy << std::endl;
}

void StatisticalPainter::drawCircle(int cx, int cy, unsigned int r) const
{
   std::cout << "drawCircle center " << " x = " << cx << " y = " << cy << " radius = " << r << std::endl;
}

}
