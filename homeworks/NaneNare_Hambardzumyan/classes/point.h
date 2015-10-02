#ifndef MY_POINT 
#define MY_POINT 

#include <iostream>

class MyPoint {
    public:
        void setX(float x);
        void setY(float y);
        float getX();
        float getY();
        MyPoint(float _x , float _y );
        MyPoint(MyPoint&);
        ~MyPoint();
    private:
        float x;
        float y;
};

#endif 
