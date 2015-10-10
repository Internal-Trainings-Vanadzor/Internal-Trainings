#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"

class Line{
    public:
        Line(Point start, Point end);
        const float getLength();
        const float area();
        const bool contains(Point point);
    private:
        Point m_start;
        Point m_end;

};

#endif
