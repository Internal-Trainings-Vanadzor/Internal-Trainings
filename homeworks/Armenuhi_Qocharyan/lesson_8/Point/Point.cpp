#ifndef MY_POINT_1 
#define MY_POINT_1
#include "Point.hpp"

Point::Point(float x1, float y1){
    this->x = x1;
    this->y = y1;
}

bool Point::isMyPoint(float x1, float y1){
    return ((this->x == x1) && (this->y == y1));
}

#endif
