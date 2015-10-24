#include "Painter.h"
#include <cassert>
using namespace Geometry;

Painter::Painter(const Canvas arg ): m_canvas(arg){
}
Painter::Painter(const Painter& arg):m_canvas(arg.m_canvas){

}
Painter::~Painter(){
}
/* Chart */
void Painter::drawChart(const SizeType** area) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Text */
void Painter::drawText(const Text& arg) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Point */
void Painter::drawPoint(const Point& p) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawPoint(const SizeType& x, const SizeType& y) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Line */
void Painter::drawLine(const Line& line) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawLine(const SizeType& x1, const SizeType& y1,
        const SizeType& x2, const SizeType& y2) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Rect */
void Painter::drawRect(const Rect& rect) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawRect(const SizeType& x1, const SizeType& y1,
        const SizeType& x2, const SizeType& y2,
        const SizeType& x3, const SizeType& y3,
        const SizeType& x4, const SizeType& y4) const{
}
/* Triangle */
void Painter::drawTriangle(const Triangle& trg) const{
}
void Painter::drawTriangle(const SizeType& x1, const SizeType& y1,
        const SizeType& x2, const SizeType& y2,
        const SizeType& x3, const SizeType& y3) const{
}
/* Circle */
void Painter::drawCircle(const Circle& crc) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawCircle(const SizeType& x, const SizeType& y,
        const SizeType& r) const{
    assert(false && "TODO: The method is not implemented yet");
}
/* Ellipse */
void Painter::drawEllipse(const Ellipse& crc) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawEllipse(const SizeType& x1, const SizeType& y1,
        const SizeType& x2, const SizeType& y2,
        const SizeType d) const{
    assert(false && "TODO: The method is not implemented yet");
}
void Painter::drawEllipse(const SizeType& x, const SizeType& y,
        const SizeType& r1, const SizeType& r2) const{
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
