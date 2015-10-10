#ifndef RECT_HPP
#define RECT_HPP

#include "Point.hpp"

class Rect{
    public:
        Rect(Point A, float height, float width);
        const float area();
        const bool contains(Point point);
    private:
        Point m_A;
        float m_height;
        float m_width;

};

#endif
