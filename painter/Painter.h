#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <string>
#include "Geometry.h"

namespace Geometry {

typedef string Text;
typedef char SymbType;
typedef unsigned int SizeType;
typedef SizeType Colour;


//TODO: remove
class Shape {
};

class Canvas {
};

class Painter {
    public:
        Painter(const Canvas arg = null);
        Painter(const Painter& arg);
        ~Painter();
    public:
        /* Chart */
        void drawChart(const SizeType** area) const;
        /* Text */
        void drawText(const Text& arg) const;
        /* Point */
        void drawPoinType(const Point& p) const;
        void drawPoinType(const SizeType& x, const SizeType& y) const;
        /* Line */
        void drawLine(const Line& line) const;
        void drawLine(const SizeType& x1, const SizeType& y1,
                const SizeType& x2, const SizeType& y2) const;
        /* Rect */
        void drawRect(const Rect& rect) const;
        void drawRect(const SizeType& x1, const SizeType& y1,
                const SizeType& x2, const SizeType& y2,
                const SizeType& x3, const SizeType& y3,
                const SizeType& x4, const SizeType& y4) const;
        /* Triangle */
        void drawTriangle(const Triangle& trg) const;
        void drawTriangle(const SizeType& x1, const SizeType& y1,
                const SizeType& x2, const SizeType& y2,
                const SizeType& x3, const SizeType& y3) const;
        /* Circle */
        void drawCircle(const Circle& crc) const;
        void drawCircle(const SizeType& x, const SizeType& y,
                const SizeType& r) const;
        /* Ellipse */
        void drawEllipse(const Ellipse& crc) const;
        void drawEllipse(const SizeType& x1, const SizeType& y1,
                const SizeType& x2, const SizeType& y2,
                const SizeType d) const;
        void drawEllipse(const SizeType& x, const SizeType& y,
                const SizeType& r1, const SizeType& r2) const;
        /* Shape */
        void drawShape(const Shape& shape) const;
        /* work with member */
        void setCanvas(const Canvas& arg);
        void setColour(const Colour& arg);
        void setSymb(const SymbType& arg);
        void setBackground();
        Colour getBackground() const;
        Colour getColour() const;
        Canvas getCanvas() const;
        SymbType getSymb() const;
    private:
        Canvas m_canvas;
};

}
#endif //PAINTER_HPP
