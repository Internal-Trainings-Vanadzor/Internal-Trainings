#ifndef MY_POINT
#define MY_POINT
class Point{
    private:
        float x;
        float y;
    public:
        Point(float x, float y);
        float getX() const;
        float getY() const;
        float distance(Point piont) const;
        float area() const;
        bool isContains(Point piont) ;
};
#endif
