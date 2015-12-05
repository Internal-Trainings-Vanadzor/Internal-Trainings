#include "Painter.h"
#include "Geometry.h"
#include "StatisticalPainter.h"
#include "Utility.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include "Circle.h"


void drawShapes(const std::vector<Shape*>& shapes, ShapePainter* sp)
{
    Pen pen;
    pen.symbol = 'a';
	for (size_t i = 0; i < shapes.size(); ++i)
	{
        pen.color = rand() % 255;
        sp->setPen(pen);
		sp->drawShape(*shapes[i]);
	}
}

int main()
{
	// Test Graphical Painter
	Pen pen;
	pen.color = 1;
	pen.symbol = '*';
	Pen pen1;
	pen1.color = 1;
	pen1.symbol = 'a';

	IM_Canvas*  canvas1 = new IM_Canvas(40,60, pen);
	ShapePainter* sp1 = new Painter(canvas1);
	sp1->setPen(pen1);
    std::vector <Shape*> shapes;
    static time_t t = time(0);
    unsigned int u_t(t);
    srand(u_t);
    u_t = rand() % 40;
    for (int i = 0; i<10; i++){
        Point start_point(rand() % 30 + 1, rand() % 50 + 1);
        Point end_point(rand() % 40, rand() % 60);
        Point tr_point( rand() % 20 + 10, rand() % 40 + 10);
        shapes.push_back(new Triangle(start_point,end_point, tr_point ));
        shapes.push_back(new Circle(tr_point, 10));
        shapes.push_back(new Rect(start_point,5, 10 ));
        shapes.push_back(new Line(start_point,end_point ));
    }
    drawShapes(shapes, sp1);
	canvas1->CanvasView();
	canvas1->canvasViewToFile();
	return 0;
}
