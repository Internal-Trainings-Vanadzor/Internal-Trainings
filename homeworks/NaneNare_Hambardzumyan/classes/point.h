#ifndef MY_POINT 
#define MY_POINT 

#include <iostream>

class MyPoint {
    public:
        void setX(const float& x);
        void setY(const float& y);
        const float& getX() const;
        const float& getY() const;
        MyPoint(const float& _x , const float& _y );
        MyPoint(const MyPoint&);
        ~MyPoint();
        float area() const;
        float distanceTo(const MyPoint&) const;
        bool isContains(const MyPoint&) const;
    private:
        float x;
        float y;
};

#endif 
