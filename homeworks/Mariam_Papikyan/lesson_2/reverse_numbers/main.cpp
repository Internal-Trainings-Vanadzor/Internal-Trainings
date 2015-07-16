#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int numberReverser(int originalNumber){
static int actualNumber=0;
if(originalNumber==0){
return actualNumber;
} 
actualNumber=actualNumber*10+ originalNumber%10;
numberReverser(originalNumber/10);
}

int main()
{
int guestNumberToReverse;
cout<<"Input your own number to reverse : ";
cin>>guestNumberToReverse;
cout<<"The reversed number of your input is: "<<numberReverser(guestNumberToReverse)<<endl;
return 0;
}