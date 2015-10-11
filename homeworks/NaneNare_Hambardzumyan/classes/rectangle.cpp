#include "rectangle.h"

void MyRectangle::setPoint1(const MyPoint& arg) {
    this->_point1 = arg;
}

void MyRectangle::setPoint2(const MyPoint& arg) {
    this->_point2 = arg;
}

void MyRectangle::setPoint3(const MyPoint& arg) {
    this->_point3 = arg;
}

void MyRectangle::setPoint4(const MyPoint& arg) {
    this->_point4 = arg;
}

const MyPoint& MyRectangle::getPoint1() const {
    return _point1;
}

const MyPoint& MyRectangle::getPoint2() const {
    return _point2;
}

const MyPoint& MyRectangle::getPoint3() const {
    return _point3;
}

const MyPoint& MyRectangle::getPoint4() const {
    return _point4;
}

MyRectangle::MyRectangle(const MyPoint& _p1, const MyPoint& _p2,
        MyPoint _p3, MyPoint _p4) {
    _point1 = _p1;
    _point2 = _p2;
    _point3 = _p3;
    _point4 = _p4;
}

MyRectangle::MyRectangle(const MyRectangle& arg) {
    _point1 = arg._point1;
    _point2 = arg._point2;
    _point3 = arg._point3;
    _point4 = arg._point4;
}

MyRectangle::~MyRectangle() {
    _point1.~MyPoint();
    _point2.~MyPoint();    
    _point3.~MyPoint();
    _point4.~MyPoint();
}

float MyRectangle::area() const {
    return area(_point1,_point2,_point3);
}

float MyRectangle::area(const MyPoint& point1, const MyPoint& point2,
        const MyPoint& point3) const {
    float d1 = point1.distanceTo(point2);
    float d2 = point3.distanceTo(point2);
    return d1*d2;
}

bool MyRectangle::isContains(const MyPoint& arg) const {
    //TODO:
    return false;
}
