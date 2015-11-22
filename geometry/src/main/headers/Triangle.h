#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "Shape.h"
#include "Geometry.h"
using namespace Geometry;

class Triangle:public Shape {

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

	const AreaType area() const;
	bool contains(const Point& p) const;
	ShapeType getType() const 
	{ return triangle; }
private:
	Point m_a;
	Point m_b;
	Point m_c;
};
#endif
