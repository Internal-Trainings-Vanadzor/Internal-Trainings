#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <windows.h>
#include <string>

enum COLOR {WHITE, BLACK, RED};

class UI_Point {
    public:
        int x;
        int y;
        COLOR color;
};

class IM_Canvas{
public:
    IM_Canvas();
	IM_Canvas(unsigned int, unsigned int, char, int);
   ~IM_Canvas();
   void CanvasView();
   void setBackgroundColor(int);//Done for Windows
   void setPointSign(char);
   void setPointColor(int);//TODO 
   void setPoint(unsigned int,unsigned int);

private:
	unsigned int m_width;
    unsigned int m_height;
	int m_backgroundColor;
    std::vector<UI_Point> m_points;
	char m_sign;
	char** Matrix;
	
};

#endif