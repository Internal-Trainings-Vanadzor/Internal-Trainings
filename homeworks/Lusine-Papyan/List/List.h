
//Creats pointers for list elemnts
struct element {
public:
	element* prev;
	element* next;
	int data;

	element(int d);
	element();

	void connect(element* element);
};

//Creats list
class List {
private:
	element* last;
	element* first;
	int count;
public:
	List();
	~List();

	void push_back(const int& data);
	void push_front(const int& data);
	void insert(const int& data, const int& position);
	void erase(const int& pos);
	void pop_front();
	void pop_back();
	void clear();
	void show();

	int front();
	int back();
	int size();

	bool empty();

	List& operator= (const List& element);
};