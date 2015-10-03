#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"

class Line{
    public:
        Line(Point* start, Point* end);
        float getLength();
        bool contains(Point* point);
        ~Line();
    private:
        Point* m_start;
        Point* m_end;

};

#endif
