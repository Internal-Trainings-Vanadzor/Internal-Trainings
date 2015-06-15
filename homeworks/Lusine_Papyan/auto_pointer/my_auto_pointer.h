class my_auto_pointer {
private:
	int* pointer;

public:
	my_auto_pointer(int* obj);
	~my_auto_pointer();
	my_auto_pointer& operator=(my_auto_pointer& object);
	void my_auto_pointer::reset(int value);
	const int get()const;
};