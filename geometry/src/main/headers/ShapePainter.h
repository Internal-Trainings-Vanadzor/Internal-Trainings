#ifndef SHAPEPAINTER_HPP
#define SHAPEPAINTER_HPP

#include <string>
#include "Geometry.h"
#include "Point.h"
#include "Canvas.h"
#include "Line.h"
#include "Rect.h"
#include "Triangle.h"
#include "Circle.h"
#include "Ellipse.h"

using namespace Geometry;

typedef std::string Text;
typedef char SymbType;
typedef unsigned int SizeType;
typedef SizeType Colour;

class ShapePainter {
        public:
            /* Point */
            virtual void drawPoint(const Point& p)  = 0;
            /* Line */
            virtual void drawLine(const Line& line)  = 0;
            /* Rect */
            virtual void drawRect(const Rect& rect)  = 0;
            /* Triangle */
            virtual void drawTriangle(const Triangle& trg)  = 0;
            /* Circle */
            virtual void drawCircle(const Circle& crc)  = 0;
            /* Ellipse */ 
            //TBD
            /* Shape */
            virtual void drawShape(const Shape& shape) const = 0;
            /* work with member */
            virtual void setCanvas(IM_Canvas& arg) = 0;
            virtual void setColour(const Colour& arg) = 0;
            virtual void setSymb(const SymbType& arg) = 0;
            virtual void setBackground(const Colour& arg) = 0;
            virtual Colour getBackground() const = 0;
            virtual Colour getColour() const = 0;
            virtual IM_Canvas getCanvas() const = 0;
            virtual SymbType getSymb() const = 0;
};
#endif //SHAPEPAINTER_HPP
