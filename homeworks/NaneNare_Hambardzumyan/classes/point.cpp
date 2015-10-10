#include "point.h"
#include <cmath>

MyPoint::MyPoint(const float& _x = 0.0, const float& _y = 0.0) 
    : x(_x), y(_y)
{}

MyPoint::MyPoint(const MyPoint& arg) {
    this->x = arg.x;
    this->y = arg.y;
}

MyPoint::~MyPoint() {
    x = 0;
    y = 0;
}

void MyPoint::setX(const float& x) {
    this->x = x;
}

void MyPoint::setY(const float& y) {
    this->y = y;
}

const float& MyPoint::getX() const {
    return x;
} 
const float& MyPoint::getY() const {
    return y;
}
float MyPoint::area() const {
    return 0;
}
bool MyPoint::isContains(const MyPoint& arg) const {
    if ((arg.getX() == this->x)&&(arg.getY() == this->y)) {
        return true;
    } 
    return false;
}
float MyPoint::distanceTo(const MyPoint& arg) const {
    float x1 = this->x - arg.getX();
    float y1 = this->y - arg.getY();
    float d = sqrt(x1*x1 + y1*y1);
    return d;
}
