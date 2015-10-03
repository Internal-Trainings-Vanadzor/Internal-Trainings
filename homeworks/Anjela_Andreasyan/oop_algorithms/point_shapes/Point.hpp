#ifndef POINT_HPP
#define POINT_HPP

class Point{
    public:
        Point(float x, float y);
        float getX();
        float getY();
    private:
        float m_x;
        float m_y;

};

#endif
