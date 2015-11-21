#include "Painter.h"
#include "Geometry.h"
#include "StatisticalPainter.h"
#include "Utility.h"
#include "Point.h"
#include <iostream>
#include <vector>

int main()
{

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
    // Test Graphical Painter
    Point start_point(5,5);
    Point end_point(15,15);
    Line line(start_point,end_point);
    info in;
    in.point_info[0] = '6';
    in.point_info[1] = '5';
    in.point_info[2] = '5';
    in.point_info[3] = '1';
    IM_Canvas canvas(40,60,in);
    Painter c_painter(canvas);
    c_painter.setColour(in.point_matrix_info);
    c_painter.setColour(1);
    c_painter.drawPoint(start_point);
    c_painter.drawPoint(end_point);
    c_painter.drawLine(line);
    c_painter.drawCircle(10,10,5);
    canvas.CanvasView();
    std::cout<<"end main\n";
    return 0;
}
