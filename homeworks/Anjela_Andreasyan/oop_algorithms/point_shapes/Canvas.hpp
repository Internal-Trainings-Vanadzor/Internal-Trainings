#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "Line.hpp"
#include "Rect.hpp"

class Canvas{
    public:
        Canvas();
        Canvas(int height, int width);
        ~Canvas();
        const void pointComponent();
        const void drawLine(Line line);
        const void drawRect(Rect rect);
    private:
        bool** pointsMatrix;
        int canv_height;
        int canv_width;
    private:
        void setupCanvas();

};


#endif
