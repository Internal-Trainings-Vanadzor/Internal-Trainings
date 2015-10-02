#include "point.h"

MyPoint::MyPoint(float _x = 0.0, float _y = 0.0) 
    : x(_x), y(_y)
{}

MyPoint::MyPoint(MyPoint& arg) {
    this->x = arg.x;
    this->y = arg.y;
}

MyPoint::~MyPoint() {
    x = 0;
    y = 0;
}

void MyPoint::setX(float x) {
    this->x = x;
}

void MyPoint::setY(float y) {
    this->y = y;
}

float MyPoint::getX() {
    return x;
}
float MyPoint::getY() {
    return y;
}
