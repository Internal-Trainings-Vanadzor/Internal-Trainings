#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Recursive function which reverses the specified numbers 
void reverseNumberRecursive(int number)
{
    if(10 > number){
        cout<<number;
        return;
    } else {
        cout<<number%10;
        reverseNumberRecursive(number/10);
    }
}

//Reverses the specified numbers 
void reverseDigits(int digits[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        int temp = digits[i];
        digits[i] = digits[size-1-i];
        digits[size-1-i] = temp; 
    }
    for (int i = 0; i < size; i++)
    {
        cout<<digits[i];
    }
}
//Reverses the specified array of numbers using stack 
void reverseNumbersUsingStack(int arr[], int size)
{
    stack<int> digits;
    for(int i = 0; i < size; i++)
    {
        digits.push(arr[i]);   
    } 
    for(int i = 0; i < size; i++)
    {
        arr[i] = digits.top();   
        digits.pop();
    } 
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
}

int main()
{
    const int size = 5;
    int digits[size] = {1,2,3,4,5};
    cout<<"Reversed number using recursive function :\n";
    reverseNumberRecursive(12345);
    cout<<"\nReversed digits using loop:\n";
    reverseDigits(digits, size);
    cout<<"\nReversed digits using stack:\n";
    reverseNumbersUsingStack(digits, size);
    return 0;
}
