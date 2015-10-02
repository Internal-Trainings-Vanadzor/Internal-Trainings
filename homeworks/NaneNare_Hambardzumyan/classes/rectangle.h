#ifndef MY_OBJECT 
#define MY_OBJECT 

#include <iostream>
#include "point.cpp"
#include "object.cpp"

class MyRectangle {
    public:
        void setPoint1(const MyPoint& arg);
        void setPoint2(const MyPoint& arg);
        void setPoint3(const MyPoint& arg);
        void setPoint4(const MyPoint& arg);
        const MyPoint& getPoint1();
        const MyPoint& getPoint2();
        const MyPoint& getPoint3();
        const MyPoint& getPoint4();
        MyRectangle(const MyPoint& _p1, const MyPoint& _p2,
                MyPoint _p3, MyPoint _p4);
        MyRectangle(MyRectangle&);
        ~MyRectangle();
        // 
        float area();
        bool isContains(MyPoint);
    private:
        float distance(MyPoint, MyPoint);
    private:
        MyPoint _point1;
        MyPoint _point2;
        MyPoint _point3;
        MyPoint _point4;
};

#endif
