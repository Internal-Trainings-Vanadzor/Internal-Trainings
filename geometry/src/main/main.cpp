#include "Painter.h"
#include "Geometry.h"
#include "StatisticalPainter.h"
#include "Utility.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include "Circle.h"


void drawShapes(const std::vector<Shapes*>& shapes, ShapePainter* sp)
{
	for (size_t i = 0; i < shapes.size(); ++i)
	{
		sp->drawShape(*shapes[i]);
	}
}

int main()
{

	std::vector <Shape*> shapes;
	ShapePainter* sp = new Painter(canvas);

	drawShapes(shapes, sp);	
	
	ShapePainter* stp = new StatisticalPainter(canvas);
	
	drawShapes(shapes, stp);	

/*
	std::vector<Rect> rects;

	rects.push_back(Utility::createRect());
	rects.push_back(Utility::createRect());
	rects.push_back(Utility::createRect());
	rects.push_back(Utility::createRect());
	rects.push_back(Utility::createRect());

	STPainter::StatisticalPainter p;

	for (size_t i = 0; i < rects.size(); ++i)
	{
		const Rect& r = rects[i];
		std::cout << r.area() << std::endl;
		p.drawRect(r.lowerLeft().x(), r.lowerLeft().y(), r.width(), r.height());
	}

	std::cout << "----------------------------------------------------" << std::endl;

	std::vector<Triangle> triangles;

	triangles.push_back(Utility::createTriangle());
	triangles.push_back(Utility::createTriangle());
	triangles.push_back(Utility::createTriangle());
	triangles.push_back(Utility::createTriangle());
	triangles.push_back(Utility::createTriangle());
	for (size_t i = 0; i < triangles.size(); ++i)
	{
		Triangle& t = triangles[i];
		std::cout << t.area() << std::endl;
		p.drawTriangle(t.a().x(), t.a().y(), t.b().x(), t.b().y(), t.c().x(), t.c().y());
	}
*/
	// Test Graphical Painter
	Point start_point(5,5);
	Point end_point(15,15);
	Circle c(end_point, 5);
	Line line(start_point,end_point);
	Rect r(start_point, 5, 5);
	Triangle t(start_point, end_point, Point(5, 10));
	info in;
	in.point_info[0] = '6';
	in.point_info[1] = '5';
	in.point_info[2] = '5';
	in.point_info[3] = '1';

	IM_Canvas*  canvas = new IM_Canvas(40,60,in);

	ShapePainter* sp = new Painter(canvas);
	sp->setColour(1);
	sp->drawShape(line);
	sp->drawShape(r);
	sp->drawShape(c);
//	sp->drawShape(t);
//	sp->drawCircle(10,10,5);

	canvas->CanvasView();
	delete canvas;
	std::cout<<"end main\n";
	return 0;
}
