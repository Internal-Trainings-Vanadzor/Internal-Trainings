#ifndef PAINTER_HPP
#define PAINTER_HPP
#include "ShapePainter.h"


class Painter:public ShapePainter {
        public:
            Painter(IM_Canvas* arg );
            Painter(const Painter& arg);
            ~Painter();
        public:
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
                    const CoordinateType& x3, const CoordinateType& y3) const;
            /* Shape */
            void drawShape(const Shape& shape) const;
            /* work with member */
            void setCanvas(IM_Canvas* arg);
            void setPen(const Pen& arg);
            void setBackground(const Colour& arg);
            Colour getBackground() const;
            Colour getPenColour() const;
            const IM_Canvas* getCanvas() const;
            SymbType getPenSymb() const;
	private:
		IM_Canvas* m_canvas;
		Pen m_pen;
};
#endif //PAINTER_HPP
