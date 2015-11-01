#ifndef LINE_HPP
#define LINE_HPP
#include "Shape.h"
#include "Geometry.h"
using namespace Geometry;

class Line:public Shape {
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

	   const AreaType area() const
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
#endif
