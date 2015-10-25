#include <iostream>
#include "canvas.h"
#include <windows.h>

IM_Canvas::IM_Canvas()
: m_width(10)
, m_height(10)
, m_sign('*')
, m_backgroundColor(0)
{
	Matrix = new char*[m_height];
	for (unsigned int i = 0; i < m_height; i++)
	{
		Matrix[i] = new char[m_width];
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

IM_Canvas::IM_Canvas(unsigned int width, unsigned int height, char sign,int backgroundColor)
: m_width(width)
, m_height(height)
, m_sign(sign)
, m_backgroundColor(backgroundColor)
{
	Matrix = new char*[m_height];
	for (unsigned int i = 0; i < m_height; i++)
	{
		Matrix[i] = new char[m_width];
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
void IM_Canvas::setBackgroundColor(int backgroundColor)
{
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
			if ( Matrix[k][h] == 1)
			{				
				std::cout << m_sign << " ";
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
	delete[] Matrix;
}
void IM_Canvas::setPointSign(char sign)
{
	 m_sign = sign;
}
void IM_Canvas::setPoint(unsigned int x, unsigned int y)
{
	if( x < m_width && y < m_height)
	{
		Matrix[m_height-1-y][x] = 1;
	}	
}
/* :)  
int main()
{
	IM_Canvas obj0;
	IM_Canvas obj1(10,20,'.',2);
	obj0.CanvasView();
	obj1.CanvasView();
	obj0.setPoint(2,3);
	obj0.CanvasView();
	obj1.setPoint(3,3);
	obj1.setPoint(5,4);
	obj1.setPointSign('^');
	obj1.setBackgroundColor(3);
	obj1.CanvasView();
	
	
	return 0;
}
*/
