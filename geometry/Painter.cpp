#include "Painter.h"
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace Geometry;

Painter::Painter(const Canvas arg ): m_canvas(arg){
}
Painter::Painter(const Painter& arg):m_canvas(arg.m_canvas){

}
Painter::~Painter(){
}
/* Chart */
void Painter::drawChart(const CoordinateType** area) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Text */
void Painter::drawText(const Text& arg) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Point */
void Painter::drawPoint(const Point& p) const{
    drawPoint(p.x(), p.y());
}
void Painter::drawPoint(const CoordinateType& x, const CoordinateType& y) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Line */
void Painter::drawLine(const Line& line) const {
    drawLine(line.start().x(), line.start().y(), line.end().x(), line.end().y());
}


void Painter::drawLine(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2) const {
    int x_1 = x1;
    int x_2 = x2;
    int y_1 = y1;
    int y_2 = y2;
    const bool steep = (abs(y_2 - y_1) > abs(x_2 - x_1));
    if(steep) {
        std::swap(x_1, y_1);
        std::swap(x_2, y_2);
    }
    if(x_1 > x_2) {
        std::swap(x_1, x_2);
        std::swap(y_1, y_2);
    }
    const int dx = x_2 - x_1;
    const int dy = abs(y_2 - y_1);
    float error = dx / 2.0f;
    const int ystep = (y_1 < y_2) ? 1 : -1;
    int y = (int)y_1;
    const int maxX = (int)x_2;
    for(int x=(int)x_1; x <= maxX; x++) {
        if(steep) {
            drawPoint(y,x);//color
        } else {
            drawPoint(x,y);//color
        }
        error -= dy;
        if(error < 0) {
            y += ystep;
            error += dx;
        }
        error -= dy;
        if(error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

/* Rect */
void Painter::drawRect(const Rect& rect) const{
    CoordinateType x1 = rect.lowerLeft().x();
    CoordinateType y1 = rect.lowerLeft().y();
    CoordinateType x2 = x1 + rect.height();
    CoordinateType y2 = y1;
    CoordinateType x3 = x2;
    CoordinateType y3 = y2 - rect.width();
    CoordinateType x4 = x1;
    CoordinateType y4 = y3; 
    drawRect(x1,y1,x2,y2,x3,y3, x4,y4);

}
void Painter::drawRect(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2,
        const CoordinateType& x3, const CoordinateType& y3,
        const CoordinateType& x4, const CoordinateType& y4) const{
    drawLine(x1,y1, x2,y2);
    drawLine(x2,y2, x3,y3);
    drawLine(x3,y3, x4,y4);
    drawLine(x4,y4, x1,y1);
}
/* Triangle */
void Painter::drawTriangle(const Triangle& trg) const{
    drawTriangle(trg.a().x(), trg.a().y(),trg.b().x(), trg.b().y(),trg.c().x(), trg.c().y());
}
void Painter::drawTriangle(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2,
        const CoordinateType& x3, const CoordinateType& y3) const{
    drawLine(x1,y1, x2,y2);
    drawLine(x2,y2, x3,y3);
    drawLine(x3,y3, x1,y1);
}
/* Circle */
void Painter::drawCircle(const Circle& crc) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawCircle(const CoordinateType& x, const CoordinateType& y,
        const CoordinateType& r) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Ellipse */
void Painter::drawEllipse(const Ellipse& crc) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawEllipse(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2,
        const CoordinateType d) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawEllipse(const CoordinateType& x, const CoordinateType& y,
        const CoordinateType& r1, const CoordinateType& r2) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Shape */
void Painter::drawShape(const Shape& shape) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* work with member */
void Painter::setCanvas(const Canvas& arg){
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::setColour(const Colour& arg){
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::setSymb(const SymbType& arg){
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::setBackground(){
    assert(false && "TODO: The method is not implemented yet");
}
Colour Painter::getBackground() const{
    assert(false && "TODO: The method is not implemented yet");
}
Colour Painter::getColour() const{
    assert(false && "TODO: The method is not implemented yet");
}
Canvas Painter::getCanvas() const{
    assert(false && "TODO: The method is not implemented yet");
}
SymbType Painter::getSymb() const{

    assert(false && "TODO: The method is not implemented yet");
}
