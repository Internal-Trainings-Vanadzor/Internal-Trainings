#ifndef DINAMIC_ARRAY
#define DINAMIC_ARRAY

class DinamicArray
{
	int* m_buffer;
	unsigned int m_size;
	unsigned int m_max_size;
public:
	DinamicArray();
	~DinamicArray();
	int getSize()const;
	void resizeBuffer();
	void putBack(int);
	void removeFromBack();
	int getElemetById(unsigned int);
	void replaceElement(unsigned int,int);
};

#endif