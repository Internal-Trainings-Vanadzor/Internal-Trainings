#include <math.h> 

#include "Line.hpp"

Line::Line(Point* start, Point* end){
    m_start = start;
    m_end = end;
}

float Line::getLength(){
    float x_distance = (*m_end).getX() - (*m_start).getX();
    float y_distance = (*m_end).getY() - (*m_start).getY();
    float length = sqrt( x_distance * x_distance + y_distance * y_distance);
    return length;

}

bool Line::contains(Point* point){
    // line formula
    // (y-y1)/(x-x1)=(y2-y1)/(x2-x1)
    float x_distance = (*m_end).getX() - (*m_start).getX();
    float y_distance = (*m_end).getY() - (*m_start).getY();
    float point_x_distance = (*point).getX() - (*m_start).getX();
    float point_y_distance = (*point).getY() - (*m_start).getY();
    return (point_y_distance / point_x_distance) == (y_distance / x_distance);
     
}
Line::~Line(){
    delete m_start;
    delete m_end;
}
