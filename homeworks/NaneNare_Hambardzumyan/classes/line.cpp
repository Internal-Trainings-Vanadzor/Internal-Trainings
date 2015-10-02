#include "line.h"
#include <cmath>

void MyLine::setStart(const MyPoint& arg) {
    this->_start = arg;
}

void MyLine::setEnd(const MyPoint& arg) {
    this->_end = arg;
}

const MyPoint& MyLine::getStart() {
    return _start;
}

const MyPoint& MyLine::getEnd() {
    return _end;
}

MyLine::MyLine(const MyPoint& _x , const MyPoint& _y ) {
    _start = _x;
    _end = _y;
}

MyLine::MyLine(MyLine& arg) {
    this->_start = arg._start;
    this->_end = arg._end;
}

MyLine::~MyLine() {
    _start.~MyPoint();
    _end.~MyPoint();
}

// Distance
float MyLine::area() {
    return area(_start,_end);
}

bool MyLine::isContains(MyPoint arg) {
    float d1 = area();
    float d2 = area(_start,arg);
    float d3 = area(arg,_end);
    if (d3 == d1 + d2) 
        return true;
    return false;
}

// Distance
float MyLine::area(MyPoint start, MyPoint end) {
    float x1 = start.getX() - end.getX();
    float y1 = start.getY() - end.getY();
    float d = sqrt(x1*x1 + y1*y1);
    return d;
}
