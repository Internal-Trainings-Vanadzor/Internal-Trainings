#ifndef POINT_HPP
#define POINT_HPP

class Point{
    public:
        Point(float x, float y);
        Point(const Point& point);
        const float getX();
        const float getY();
        const float getDistance(Point dest);
        const float area();
    private:
        float m_x;
        float m_y;

};

#endif
