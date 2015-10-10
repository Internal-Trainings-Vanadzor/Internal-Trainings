#include <math.h> 

#include "Rect.hpp"

Rect::Rect(Point A, float height, float width): m_A(A), m_height(height), m_width(width){
}

Rect::Rect(const Rect& rect): m_A(rect.m_A), m_height(rect.m_height), m_width(rect.m_width){
}
const float Rect::area(){
    return m_height * m_width;

}

const bool Rect::contains(Point point){
    float x = point.getX();
    float y = point.getY();
    float m_x = m_A.getX();
    float m_y = m_A.getY();
    return (x >= m_x && x <= (m_x + m_width) && y >= m_y && y <= (m_y + m_height));

}
