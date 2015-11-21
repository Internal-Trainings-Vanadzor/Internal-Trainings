#ifndef PAINTER_HPP
#define PAINTER_HPP
#include "ShapePainter.h"


class Painter:public ShapePainter {
        public:
            Painter(IM_Canvas arg );
            Painter(const Painter& arg);
            ~Painter();
        public:
            /* Chart */
            void drawChart(const CoordinateType** area) ;
            /* Text */
            void drawText(const Text& arg) ;
            /* Point */
            void drawPoint(const Point& p) ;
            void drawPoint(const CoordinateType& x, const CoordinateType& y) ;
            /* Line */
            void drawLine(const Line& line) ;
            void drawLine(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2) ;
            /* Rect */
            void drawRect(const Rect& rect);
            void drawRect(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2,
                    const CoordinateType& x3, const CoordinateType& y3,
                    const CoordinateType& x4, const CoordinateType& y4) ;
            /* Triangle */
            void drawTriangle(const Triangle& trg) ;
            void drawTriangle(const CoordinateType& x1, const CoordinateType& y1,
                    const CoordinateType& x2, const CoordinateType& y2,
                    const CoordinateType& x3, const CoordinateType& y3) ;
            /* Circle */
            void drawCircle(const Circle& crc) ;
            void drawCircle(const CoordinateType& x, const CoordinateType& y,
                    const DistanceType& r) ;
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
            void setCanvas(IM_Canvas& arg);
            void setColour(const Colour& arg);
            void setSymb(const SymbType& arg);
            void setBackground(const Colour& arg);
            Colour getBackground() const;
            Colour getColour() const;
            IM_Canvas getCanvas() const;
            SymbType getSymb() const;
	private:
		IM_Canvas m_canvas;
        Colour m_colour;
        SymbType m_symb;
};
#endif //PAINTER_HPP
