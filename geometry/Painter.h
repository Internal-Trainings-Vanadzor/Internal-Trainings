#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <string>
#include "Geometry.h"

namespace Geometry {

    typedef std::string Text;
    typedef char SymbType;
    typedef unsigned int SizeType;
    typedef SizeType Colour;


    //TODO: remove
    class Shape {
    };

    class Ellipse {
        // TODO mv to Geometry
    };

    class Canvas {
        public:
            Canvas();
            Canvas(const Canvas& arg );
    };

    class Painter {
        public:
            Painter(const Canvas arg );
            Painter(const Painter& arg);
            ~Painter();
        public:
            /* Chart */
            void drawChart(const CoordinateType** area) const;
            /* Text */
            void drawText(const Text& arg) const;
            /* Point */
            void drawPoint(const Point& p) const;
            void drawPoint(const CoordinateType& x, const CoordinateType& y) const;
            /* Line */
            void drawLine(const Line& line) const;
            void drawLine(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2) const;
            /* Rect */
            void drawRect(const Rect& rect) const;
            void drawRect(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2,
                    const CoordinateType& x3, const CoordinateType& y3,
                    const CoordinateType& x4, const CoordinateType& y4) const;
            /* Triangle */
            void drawTriangle(const Triangle& trg) const;
            void drawTriangle(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2,
                    const CoordinateType& x3, const CoordinateType& y3) const;
            /* Circle */
            void drawCircle(const Circle& crc) const;
            void drawCircle(const CoordinateType& x, const CoordinateType& y,
                    const CoordinateType& r) const;
            /* Ellipse */
            void drawEllipse(const Ellipse& crc) const;
            void drawEllipse(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2,
                    const CoordinateType d) const;
            void drawEllipse(const CoordinateType& x, const CoordinateType& y,
                    const CoordinateType& r1, const CoordinateType& r2) const;
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
