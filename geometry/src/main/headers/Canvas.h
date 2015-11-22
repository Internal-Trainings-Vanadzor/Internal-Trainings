#ifndef CANVAS_H
#define CANVAS_H

union info {
	int point_matrix_info;
	char point_info[4]; 
};

class IM_Canvas {
	public:
		IM_Canvas(unsigned int, unsigned int); // TODO do we need to pass info in constructor?
		~IM_Canvas();
		void CanvasView();
		virtual void setBackgroundiPen(Pen);//Done for Windows // TODO Pen
		virtual void setPoint(unsigned int,unsigned int, Pen );

	private:
		IM_Canvas(const IM_Canvas&);

	private:
		unsigned int m_width;
		unsigned int m_height;
		//int* Matrix -> size = h * w;
		//char* h*w / 8 

};

#endif
