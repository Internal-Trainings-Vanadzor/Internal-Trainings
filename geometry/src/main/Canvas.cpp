#include <iostream>
#include "headers/Canvas.h"
//#include <windows.h>

IM_Canvas::IM_Canvas(unsigned int width, unsigned int height)//, info backgroundColor)
: m_width(width)
, m_height(height)
//, m_backgroundColor(backgroundColor.point_matrix_info)
{
	Matrix = new int*[m_height];
	for (unsigned int i = 0; i < m_height; i++)
	{
		Matrix[i] = new int[m_width];
	}

	for (unsigned int i = 0; i < m_height; i++)
	{
		Matrix[i][0] = 1;
	}

	for (unsigned int j = 0; j < m_width; j++)
	{
		Matrix[m_height-1][j] = 1;
	}

	for (unsigned int i = 0; i < m_height-1; i++)
		for(unsigned int j = 1; j < m_width; j++)
		{
			Matrix[i][j] = 0;
		}
	#ifdef _WIN32
		setBackgroundColor(m_backgroundColor);
		#ifdef _WIN64
			setBackgroundColor(m_backgroundColor);
		#endif
	#endif
}
void IM_Canvas::setBackgroundColor(unsigned int backgroundColor)
{
	m_backgroundColor = backgroundColor;
    /*
     * TODO look at this later
	const WORD colors[] =
		{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
		};
	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD   index   = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	SetConsoleTextAttribute( hstdout, colors[backgroundColor] );
    */
}

void IM_Canvas::setBackgroundPen(Pen pen) {
	m_pen = pen;	
//TBD
}

void IM_Canvas::CanvasView()
{
	#ifdef _WIN32
		setBackgroundColor(m_backgroundColor);
		#ifdef _WIN64
			setBackgroundColor(m_backgroundColor);
		#endif
	#endif
	for (unsigned int k = 0; k < m_height; k++)
	{
		for (unsigned int h = 0; h < m_width; h++)
		{
			if ( Matrix[k][h] != 0) // TODO need to be updated to check the last character
			{			
				std::cout << m_pen.symbol <<" ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

IM_Canvas::~IM_Canvas()
{
	for (unsigned int i = 0; i < m_height; i++)
	{
		delete[] Matrix[i];
	}
	delete [] Matrix;
}


void IM_Canvas::setPoint(unsigned int x, unsigned int y)
{
	if( x < m_width && y < m_height)
	{
		std::cout << m_pen.color << "       ****  ///"<< "\n";
		Matrix[m_height-1-y][x] = m_pen.color;
	}	
}

void IM_Canvas::setPoint(unsigned int x, unsigned int y, Pen pen)
{
	if( x < m_width && y < m_height)
	{
		m_pen = pen;
		Matrix[m_height-1-y][x] = pen.color;
	}	
}
/*  
int main()
{
	info in;
	in.point_info[0] = '256'; //TODO is this a char, should we use char for this case?
	in.point_info[1] = '125';
	in.point_info[2] = '145';
	in.point_info[3] = '1';
	IM_Canvas obj1(10,20,in);
	obj1.CanvasView();
	obj1.setPoint(3,3,in);
	obj1.setPoint(5,4,in);
	//obj1.setBackgroundColor(3);
	obj1.CanvasView();

	
	
	return 0;
}
*/
