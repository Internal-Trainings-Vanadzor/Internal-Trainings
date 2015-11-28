#ifndef SHAPEPAINTER_HPP
#define SHAPEPAINTER_HPP

#include <iostream>

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

public :
            /* Shape */
            void drawShape(const Shape& shape) 
	    {
		switch(shape.getType())
		{
			case ShapeType::rect:
				drawRect(static_cast<const Rect&>(shape));
				break;
			case ShapeType::line:
				drawLine(static_cast<const Line&>(shape));
				break;
			case ShapeType::circle: 
            			drawCircle(static_cast<const Circle&>(shape));
				break;
			default :
				throw 1;	
		}
	    }
            
protected :
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
            /* work with member */
public :
            virtual void setCanvas(IM_Canvas* arg) = 0;
            virtual void setPen(const Pen& pen) = 0; //TODO setPen -> Pen { color, style }
            virtual void setBackground(const Colour& arg) = 0;
            virtual Colour getBackground() const = 0;
            virtual Colour getPenColour() const = 0;
            virtual SymbType getPenSymb() const = 0;
            virtual const IM_Canvas* getCanvas() const = 0;
};
#endif //SHAPEPAINTER_HPP
