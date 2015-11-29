#include "Painter.h"
#include "Canvas.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace Geometry;

Painter::Painter(IM_Canvas* arg ) : m_canvas(arg){
}
Painter::Painter(const Painter& arg):m_canvas(arg.m_canvas){

}
Painter::~Painter(){
}
/* Point */
void Painter::drawPoint(const Point& p) {
    drawPoint(p.x(), p.y());
}
void Painter::drawPoint(const CoordinateType& x, const CoordinateType& y) {
    m_canvas->setPoint(x, y, m_pen);
}
/* Line */
void Painter::drawLine(const Line& line) {
    drawLine(line.start().x(), line.start().y(), line.end().x(), line.end().y());
}


void Painter::drawLine(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2)  {
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
    int y = y_1;
    for(int x=(int)x_1; x <= x_2; x++) {
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
    }
}

/* Rect */
void Painter::drawRect(const Rect& rect){
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

// TODO this method should be updated either arguments list should be changed to get ll coordinate and height / width or modifier should be changed to a private to avoid checking whether it is rect or not
void Painter::drawRect(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2,
        const CoordinateType& x3, const CoordinateType& y3,
        const CoordinateType& x4, const CoordinateType& y4) {
    drawLine(x1,y1, x2,y2);
    drawLine(x2,y2, x3,y3);
    drawLine(x3,y3, x4,y4);
    drawLine(x4,y4, x1,y1);
}
/* Triangle */
void Painter::drawTriangle(const Triangle& trg) {
    drawTriangle(trg.a().x(), trg.a().y(),trg.b().x(), trg.b().y(),trg.c().x(), trg.c().y());
}
void Painter::drawTriangle(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2,
        const CoordinateType& x3, const CoordinateType& y3) {
    drawLine(x1,y1, x2,y2);
    drawLine(x2,y2, x3,y3);
    drawLine(x3,y3, x1,y1);
}
/* Circle */
void Painter::drawCircle(const Circle& crc) {
    drawCircle(crc.center().x(),crc.center().y(),crc.radius());
}
void Painter::drawCircle(const CoordinateType& x, const CoordinateType& y,
        const DistanceType& r) {
    const float deltaDegree = M_PI/180; // radian
    const CoordinateType deltaStep = 5;
    for (int i = 1; i <= 360; i += deltaStep) {
        float degree = i * deltaDegree;
        CoordinateType _x = x + cos(degree)*r;
        CoordinateType _y = y + sin(degree)*r;
        drawPoint(_x,_y);
    }
}
/* Ellipse */
/*void Painter::drawEllipse(const Ellipse& crc) const{
    assert(false && "TODO: The method is not implemented yet");
}*/
void Painter::drawEllipse(const CoordinateType& x1, const CoordinateType& y1,
        const CoordinateType& x2, const CoordinateType& y2,
        const CoordinateType& x3, const CoordinateType& y3) const{
    assert(false && "TODO: The method is not implemented yet");
}

/* Shape */
void Painter::drawShape(const Shape& shape) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* work with member */
void Painter::setCanvas(IM_Canvas* arg){
    m_canvas = arg;
}
void Painter::setPen(const Pen& pen){
    m_pen = pen;
}

void Painter::setBackground(const Colour& arg){
//    m_canvas.setBackground(arg);
    assert(false && "TODO: The method is not implemented yet");
}

Colour Painter::getBackground() const{
    assert(false && "TODO: The method is not implemented yet");
    //return m_canvas.getBackground();
}
Colour Painter::getPenColour() const{
    return m_pen.color;
}
const IM_Canvas* Painter::getCanvas() const{
    return m_canvas;
}
SymbType Painter::getPenSymb() const{
    return m_pen.symbol;
}
