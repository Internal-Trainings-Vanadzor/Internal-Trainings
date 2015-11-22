#ifndef RECT_HPP
#define RECT_HPP
#include "Shape.h"
#include "Geometry.h"
using namespace Geometry;

class Rect : public Shape {
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

	   const Geometry::AreaType area() const
	   {
		  return m_height * m_width;
	   }

	   bool contains(const Point& p) const;

	   ShapeType getType() const
	   { return rect; }

	private:
	   Point m_lowerLeft;
	   SizeType m_height;
	   SizeType m_width;

};
#endif
