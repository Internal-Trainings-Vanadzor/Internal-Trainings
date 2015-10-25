#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <string>
#include "Geometry.h"
#include "Point.h"
#include "Canvas.h"
#include "Line.h"
#include "Rect.h"
#include "Triangle.h"
#include "Circle.h"
#include "Ellipse.h"


typedef std::string Text;
typedef char SymbType;
typedef unsigned int SizeType;
typedef SizeType Colour;

class Painter {
        public:
            Painter(const IM_Canvas arg );
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
            /* Ellipse */ //temporarily disabled
            //void drawEllipse(const Ellipse& crc) const;
            void drawEllipse(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2,
                    const CoordinateType d) const;
            void drawEllipse(const CoordinateType& x, const CoordinateType& y,
                    const CoordinateType& r1, const CoordinateType& r2) const;
            /* Shape */
            void drawShape(const Shape& shape) const;
            /* work with member */
            void setCanvas(const IM_Canvas& arg);
            void setColour(const Colour& arg);
            void setSymb(const SymbType& arg);
            void setBackground();
            Colour getBackground() const;
            Colour getColour() const;
            IM_Canvas getCanvas() const;
            SymbType getSymb() const;
	private:
		IM_Canvas m_canvas;
};
#endif //PAINTER_HPP
