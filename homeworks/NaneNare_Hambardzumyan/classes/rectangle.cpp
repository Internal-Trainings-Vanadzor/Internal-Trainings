void MyRectangle::setPoint1(const MyPoint& arg) {
    this->_point1 = arg._point1;
}

void MyRectangle::setPoint2(const MyPoint& arg) {
    this->_point2 = arg._point2;
}

void MyRectangle::setPoint3(const MyPoint& arg) {
    this->_point3 = arg._point3;
}

void MyRectangle::setPoint4(const MyPoint& arg) {
    this->_point4 = arg._point4;
}

const MyPoint& MyRectangle::getPoint1() {
    return _point1;
}

const MyPoint& MyRectangle::getPoint2() {
    return _point2;
}

const MyPoint& MyRectangle::getPoint3() {
    return _point3;
}

const MyPoint& MyRectangle::getPoint4() {
    return _point4;
}

MyRectangle::MyRectangle(const MyPoint& _p1, const MyPoint& _p2,
        MyPoint _p3, MyPoint _p4) {
    _point1 = _p1;
    _point2 = _p2;
    _point3 = _p3;
    _point4 = _p4;
}

MyRectangle::MyRectangle(MyRectangle& arg) {
    _point1 = arg._point1;
    _point2 = arg._point2;
    _point3 = arg._point3;
    _point4 = arg._point4;
}

MyRectangle::~MyRectangle() {
    _point1.~MyPoint();
    _point2.~MyPoint();    
    _point3.~MyPoint();
    _point4.~MyPoint();
}

float MyRectangle::area() {
    return area(_point1,_point2,_point3);
}

float MyRectangle::area(MyPoint point1, MyPoint point2,
        MyPoint point3) {
    float d1 = distance(point1,point2);
    float d2 = distance(point3,point2);
    return d1*d2;
}

bool MyRectangle::isContains(MyPoint arg) {
    //TODO:
    return false;
}

float MyRectangle::distance(MyPoint start, MyPoint end) {
    float x1 = start.getX() - end.getX();
    float y1 = start.getY() - end.getY();
    float d = sqrt(x1*x1 + y1*y1);
    return d;
}
