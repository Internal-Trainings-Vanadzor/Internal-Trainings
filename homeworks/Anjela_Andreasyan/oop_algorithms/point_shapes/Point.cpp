#include <math.h>

#include "Point.hpp"

Point::Point(float x, float y): m_x(x), m_y(y) {
}

Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y){
}

const float Point::getX(){
    return m_x;
}

const float Point::getY(){
    return m_y;
}

const float Point::getDistance(Point dest){
    float x_distance = dest.getX() - this->getX();
    float y_distance = dest.getY() - this->getY();
    float length = sqrt( x_distance * x_distance + y_distance * y_distance);
    return length;
}

const float Point::area(){
    return 0;
}
