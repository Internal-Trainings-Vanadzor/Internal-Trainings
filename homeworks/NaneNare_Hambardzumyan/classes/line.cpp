#include "line.h"
#include <cmath>

void MyLine::setStart(const MyPoint& arg) {
    this->_start = arg;
}

void MyLine::setEnd(const MyPoint& arg) {
    this->_end = arg;
}

const MyPoint& MyLine::getStart() const {
    return _start;
}

const MyPoint& MyLine::getEnd() const {
    return _end;
}

MyLine::MyLine(const MyPoint& _x , const MyPoint& _y ) {
    _start = _x;
    _end = _y;
}

MyLine::MyLine(const MyLine& arg) {
    this->_start = arg._start;
    this->_end = arg._end;
}

MyLine::~MyLine() {
}

// Distance
float MyLine::area() const {
    return _start.distanceTo(_end);
}

bool MyLine::isContains(const MyPoint& arg) const {
    float d1 = area();
    float d2 = _start.distanceTo(arg);
    float d3 = arg.distanceTo(_end);
    if (d3 == d1 + d2) 
        return true;
    return false;
}
