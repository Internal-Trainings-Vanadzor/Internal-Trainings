#ifndef MY_POINT_1
#define MY_POINT_1
#include <math.h>
#include "Point.hpp"

Point::Point(float x, float y): x(x), y(y) {
}

float Point::getX() const {
    return this->x;
}

float Point::getY() const {
    return this->y;
}


float Point::distance(Point piont) const {
     float x_coor = piont.getX() - this->getX();
     float y_coor = piont.getY() - this->getY();
     return sqrt( x_coor * x_coor + y_coor * y_coor);
}

float Point::area() const {
    return 0;
}

bool Point::isContains(Point point) {
    return ((point.getX() == this->x) && (point.getY() == this->y));
}

#endif
