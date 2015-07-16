#include <iostream>
using namespace std;

class Counter{
	
	//private variables
	private: 
		static int count;
		int number;

	//public variables
	public:
		/*The class's constructor description*/
		Counter(){
			count++;
			cout<<"count in constructor = "<<count<<endl;
		}
		
		/*The class's constructor description with parameter*/
		Counter(int a){
			number = a;
			cout<<"number = "<<number<<endl;
		}
		
		/*The class's destructor description*/
		~Counter(){
			count--;
			cout<<"count in destructor = "<<count<<endl;
		}
		
		/*The class's copy constructor description*/
		Counter(const Counter &num_copy){
			number = num_copy.number;
			cout << "number copy = " << number << endl;
		}
};

int Counter::count = 0;

int main(){

	Counter* obj = new Counter[50];
    	delete[] obj;
	Counter obj_with_param(10);
	Counter num_copy = obj_with_param;
return 0;
};