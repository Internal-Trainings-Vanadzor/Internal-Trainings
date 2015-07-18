#ifndef MY_CUSTOM_LIST
#define MY_CUSTOM_LIST
#include <iostream>
/*
 * Node structure
 */
template <class T>
struct Node {
    T m_data;
    Node* m_next;
    Node* m_prev;
};

/*
 * custom  MyList
 */
template <class T>
class MyList{
    private:
        Node<T>* m_head;
        Node<T>* m_tail;
    public:
        // insert methods
        void push_first(T);
        void push_last(T);
        void push_index (int,T);
        // remove methods
        T pop_first();
        T pop_last();
        T pop_index (int);
        void clear();
        // get size
        int get_size();
        // Print methods
        void print_right_from(int);
        void print_left_from (int); 
        void print_index(int);
        //Constructor
        MyList();	
        //Destrcutor
        ~MyList();	
};

/*
 * Default Constructor
 */
template <class T>
MyList<T>::MyList()
{
	m_head = NULL;
	m_tail = NULL;
}

/*
 * Destrcutor
 */
template <class T>
MyList<T>::~MyList()
{
    m_head = NULL;
    m_tail = NULL;
    if ((NULL != m_head) || (NULL != m_tail) ) {
        clear();
    }
}

/*
 * push some obj from first
 */ 
template <class T>
void MyList<T>::push_first(T arg)
{
    Node<T>* temp = new Node<T>;
    if (NULL == m_head) {
        m_head = temp;
        m_tail = temp;
    } else {
        temp -> m_next  = m_head;
        temp -> m_prev = NULL;
        m_head -> m_prev = temp;
        m_head  = temp;	
    } 
    temp -> m_data = arg;
}

/*
 * push some obj from end
 */ 
template <class T>
void MyList<T>::push_last(T arg)
{
    Node<T>* temp = new Node<T>;
    if (NULL == m_tail) {
        m_head = temp;
        m_tail = temp;
    } else {
        temp -> m_next  = NULL;
        temp -> m_prev = m_tail;
        m_tail -> m_next = temp;
        m_tail = temp;	
    } 
    temp -> m_data = arg;
}

/*
 * push some obj from some position
 */ 
template <class T>
void MyList<T>::push_index(int index, T arg)
{	
    if (0 == index) {
        push_first(arg);
        return;
    } 
    if (index >= get_size()) {
        push_last(arg);
    }
    int i = 0;
    Node<T>* temp = m_head;
    while (i < index){
        temp = temp -> m_next;
        i++;
    }		
    Node<T>* obj = new Node<T>;
    obj -> m_next = temp -> m_next;
    obj -> m_prev = temp;
    temp -> m_next = obj;
    obj ->m_data = arg;
}

/*
 * pop first obj
 */ 
template <class T>
T MyList<T>::pop_first()
{
    if (NULL == m_head) {
        return 0;
    } 
    if (NULL == m_head -> m_next) {
        T value  =  m_head -> m_data;
        delete m_head;
        m_head = m_tail = NULL;
        return value;
    }
    T value  =  m_head -> m_data;
    Node<T>* temp = m_head;
    m_head = temp -> m_next;
    m_head -> m_prev = NULL;
    delete temp;
    return value;
}

/*
 * pop end obj
 */ 
template <class T>
T MyList<T>::pop_last()
{
    if (NULL == m_tail) {
        return 0;
    } 
    if (NULL == m_tail -> m_prev) {
        T value = m_tail -> m_data;
        delete m_tail;
        m_head = m_tail = NULL;
        return value;
    }
    T value  =  m_tail -> m_data;
    Node<T>* temp = m_tail;
    m_tail = temp -> m_prev;
    m_head -> m_next = NULL;
    delete temp;
    return value;
}

/*
 * pop end obj
 */ 
template <class T>
T MyList<T>::pop_index(int index)
{	
    if (0 == index) {
        return pop_first();
    } 
    if (index >= get_size()) {
        return pop_last();
    }
    int i = 0;
    Node<T>* temp = m_head;
    while (i < index){
        temp = temp -> m_next;
        i++;
    }		
    Node<T>* obj = temp -> m_prev; //new Node<T>;
    obj -> m_next = temp -> m_next;
    temp-> m_next -> m_prev = obj;
    T value = temp -> m_data;
    delete temp;
    return value;
}

/*
 * clear list
 */ 
template <class T>
void MyList<T>::clear() 
{
    if (NULL == m_head) {
        return;
    }
    Node<T>* temp = m_head;
    while ((NULL != temp) && (NULL != temp -> m_next)) {
        temp = temp -> m_next;
        delete temp -> m_prev;
    }		
    delete temp;
    m_head = m_tail = NULL;
}

/*
 * return list size
 */ 
template <class T>
int MyList<T>::get_size() 
{
    if (NULL == m_head) {
        return 0;
    }
    Node<T>* temp = m_head;
    int i = 0;
    while (NULL != temp -> m_next){
        temp = temp -> m_next;
        i++;
    }		
    return ++i;
}

/*
 * print right objects
 */ 
template <class T>
void MyList<T>::print_right_from(int index = 0) 
{
    int size = get_size();
    if (index > size) {
        std::cout << "Index is out of size: index = " << index 
            << " size = " << size << std::endl; 
        return;
    }
    if (index == size) {
        std::cout << "Last " << index  << "object is: " << m_tail -> m_data 
            << std::endl; 
        return;
    }
    if (NULL == m_head) {
        std::cout << "List is empyt." << std::endl; 
        return;
    }
    Node<T>* temp = m_head;
    int i = 0;
    do {
        i++;
        if (index > i) {
            std::cout << "Index " << i  << "object is: " << temp -> m_data 
                << std::endl; 
        }
        temp = temp -> m_next;
    } while (NULL != temp);
}

/*
 * print left objects
 */ 
template <class T>
void MyList<T>::print_left_from(int index = 0) 
{
    int size = get_size();
    if (index > size) {
        std::cout << "Index is out of size: index = " << index 
            << " size = " << size << std::endl; 
        return;
    }
    if (index == size) {
        std::cout << "Last " << index  << "object is: " << m_tail -> m_data 
            << std::endl; 
        return;
    }
    if (NULL == m_head) {
        std::cout << "List is empyt." << std::endl; 
        return;
    }
    Node<T>* temp = m_tail;
    int i = size;
    do {
        i--;
        if (index < i) {
            std::cout << "Index " << i  << "object is: " << temp -> m_data 
                << std::endl; 
        }
        temp = temp -> m_prev;
    } while (NULL != temp);
}

/*
 * print left objects
 */ 
template <class T>
void MyList<T>::print_index(int index) 
{
    int size = get_size();
    if (index > size) {
        std::cout << "Index is out of size: index = " << index 
            << " size = " << size << std::endl; 
        return;
    }
    if (index == size) {
        std::cout << "Last " << index  << "object is: " << m_tail -> m_data 
            << std::endl; 
        return;
    }
    if (NULL == m_head) {
        std::cout << "List is empyt." << std::endl; 
        return;
    }
    Node<T>* temp = m_head;
    int i = 0;
    do {
        i++;
        if (index == i) {
            std::cout << "Index " << i  << "object is: " << temp -> m_data 
                << std::endl; 
            break;
        }
        temp = temp -> m_next;
    } while (NULL != temp);
}

#endif // MY_CUSTOM_LIST
