#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <string>
#include "Point.h"

union info {
    int point_matrix_info;
    char point_info[4]; 
};

class IM_Canvas {
    public:
        IM_Canvas(unsigned int, unsigned int, info); // TODO do we need to pass info in constructor?
        ~IM_Canvas();
        void CanvasView();
        void setBackgroundColor(int);//Done for Windows
        void setPoint(unsigned int,unsigned int, info);

    private:
        unsigned int m_width;
        unsigned int m_height;
        int m_backgroundColor;
        int** Matrix;

};

#endif
