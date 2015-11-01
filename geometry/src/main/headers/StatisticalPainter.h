#ifndef STATISTICAL_PAINTER_HPP
#define STATISTICAL_PAINTER_HPP

namespace STPainter {

class StatisticalPainter {

public :
   void drawPoint(int x, int y) const;
   void drawLine(int sx, int sy, int ex, int ey) const;
   void drawRect(int llx, int lly, unsigned int w, unsigned int h) const;
   void drawTriangle(int ax, int ay, int bx, int by, int cx, int cy) const;
   void drawCircle(int cx, int cy, unsigned int r) const;

};

}

#endif
