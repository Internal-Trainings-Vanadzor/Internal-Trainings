#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cassert>

namespace Geometry {

typedef int CoordinateType;
typedef double DistanceType;
typedef double AreaType;
typedef unsigned int SizeType;

class Point {

public:
   Point (CoordinateType x = 0, CoordinateType y = 0)
      : m_x(x)
      , m_y(y)
   {}

   const CoordinateType& x() const
   { 
      return m_x;
   }
   CoordinateType& x()
   { 
      return m_x;
   }

   const CoordinateType& y() const
   { 
      return m_y;
   }
   CoordinateType& y()
   { 
      return m_y;
   }

   AreaType area() const
   {
      return 0;
   }

   bool contains(const Point& p) const
   {
      return x() == p.x() && y() == p.y();
   }

   DistanceType distance(const Point&) const;

private:
   CoordinateType m_x;
   CoordinateType m_y;

};

class Line {

public:
   Line(const Point& s, const Point& e)
      : m_start(s)
      , m_end(e)
   {}

   const Point& start() const
   {
      return m_start;
   }

   Point& start()
   {
      return m_start;
   }

   const Point& end() const
   {
      return m_end;
   }

   Point& end()
   {
      return m_end;
   }

   AreaType area() const
   {
      return 0;
   }

   DistanceType length() const
   {
      return start().distance(end());
   }

   bool contains(const Point& p) const;

private:
   Point m_start;
   Point m_end;

};

class Rect{
public:
   Rect(const Point& ll, SizeType h, SizeType w)
      : m_lowerLeft(ll)
      , m_height(h)
      , m_width(w)
   {
      assert(m_height >= 0.0);
      assert(m_width >= 0.0);
   }

   const Point& lowerLeft() const
   {
      return m_lowerLeft;
   }
   Point& lowerLeft()
   {
      return m_lowerLeft;
   }

   const SizeType& height() const 
   { 
      return m_height;
   }
   SizeType& height()  
   { 
      return m_height;
   }

   const SizeType& width() const
   {
      return m_width;
   }
   SizeType& width()
   {
      return m_width;
   }

   const AreaType area() const
   {
      return m_height * m_width;
   }

   bool contains(const Point& p) const;

private:
   Point m_lowerLeft;
   SizeType m_height;
   SizeType m_width;

};

class Triangle {

public:
   Triangle(const Point& a, const Point& b, const Point& c)
      : m_a(a)
      , m_b(b)
      , m_c(c)
   {}

   const Point& a() const
   {
      return m_a;
   }
   Point& a()
   {
      return m_a;
   }
   const Point& b() const
   {
      return m_b;
   }
   Point& b()
   {
      return m_b;
   }
   const Point& c() const
   {
      return m_c;
   }
   Point& c()
   {
      return m_c;
   }

   AreaType area() const;
   bool contains(const Point& p) const;

private:
   Point m_a;
   Point m_b;
   Point m_c;
};

class Circle {

public:
   Circle(const Point& c, DistanceType r)
      : m_center(c)
      , m_radius(r)
   {}

   AreaType area() const;
   bool contains(const Point& p) const;

private:
   Point m_center;
   DistanceType m_radius;

};

}

#endif