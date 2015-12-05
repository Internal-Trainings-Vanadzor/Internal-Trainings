#ifndef CANVAS_H
#define CANVAS_H

//union info {
//	int point_matrix_info;
//	char point_info[4]; 
//};

struct Pen {
  char symbol;
  int color;
};

class IM_Canvas {
	public:
		IM_Canvas(unsigned int, unsigned int, Pen); // TODO do we need to pass info in constructor?
		~IM_Canvas();
		void CanvasView();
        void canvasViewToFile();
		virtual void setBackgroundPen(Pen);//Done for Windows // TODO Pen
		virtual void setBackgroundColor(unsigned int);
		virtual void setPoint(unsigned int,unsigned int);
		virtual void setPoint(unsigned int,unsigned int, Pen pen);

	private:
		IM_Canvas(const IM_Canvas&);

	private:
		unsigned int m_width;
		unsigned int m_height;
		unsigned int m_backgroundColor;
		//int** Matrix;
		Pen** Matrix;
		Pen m_pen;
		//int* Matrix -> size = h * w;
		//char* h*w / 8 

};

#endif
