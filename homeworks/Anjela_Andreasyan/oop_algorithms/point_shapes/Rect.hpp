#ifndef RECT_HPP
#define RECT_HPP

#include "Point.hpp"

class Rect{
    public:
        Rect(Point* A, float height, float width);
        float getArea();
        bool contains(Point* point);
        ~Rect();
    private:
        Point* m_A;
        float m_height;
        float m_width;

};

#endif
