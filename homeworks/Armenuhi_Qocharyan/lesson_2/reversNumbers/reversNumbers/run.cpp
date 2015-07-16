#include<iostream>



int reversNumber (int number) {
    static int revers_number = 0; 
    revers_number = revers_number * 10 + abs(number) % 10;
    if (abs(number) <= 9) {
	int final_number = revers_number;
	if (number < 0){
	   final_number = final_number * -1;
	}
	revers_number = 0;
	return final_number;
    } else {
	return reversNumber(number / 10);
    }
}


int main() 
{
    int num = reversNumber(-123);
    std::cout <<"revers number -123: " << num << "\n";
    num = reversNumber( 123);
    std::cout <<"revers number 123: " << num << "\n";
    num = reversNumber(0);
    std::cout <<"revers number 0: " << num << "\n";
    num = reversNumber(8);
    std::cout <<"revers number 8: " << num << "\n";
    return 0;
}
