#include<iostream>
using namespace std;

static int reverse = 0;

static int reverse_number(int num){
	
	if (num == 0){
		return -1;
	}else{
		reverse = reverse * 10;
		reverse = reverse + num%10;
		reverse_number(num/10);
		//cout<<"New Reversed Number is:  "<<reverse;
	}
	return reverse;
}

int main() {

	int input_number;
	int reversed_number;
	cout<<"Input a Number to Reverse and press Enter: ";
	cin>> input_number;
	reversed_number = reverse_number(input_number);
	cout<<"New Reversed Number is: "<< reversed_number << endl;
   
return 0;

}