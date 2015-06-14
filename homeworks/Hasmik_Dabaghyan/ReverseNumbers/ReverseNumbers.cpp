#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Reverses the specified numbers 
void reverseNumbers(int numbers[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        int temp = numbers[i];
        numbers[i] = numbers[size-1-i];
        numbers[size-1-i] = temp; 
    }
    cout<<"Reveresed results: \n";
    for (int i = 0; i < size; i++)
    {
        cout<<numbers[i]<<"\n";
    }
}
//Reverses the specified array of numbers using stack 
void reverseNumbersUsingStack(int arr[], int size)
{
    stack<int> numbers;
    for(int i = 0; i < size; i++)
    {
        numbers.push(arr[i]);   
    } 
    for(int i = 0; i < size; i++)
    {
        arr[i] = numbers.top();   
        numbers.pop();
    } 
    cout<<"Reveresed results using stack: \n";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"\n";
    }
}

int main()
{
    int size;
    cout<<"Please enter the count of numbers:\n";
    cin>>size;    
    cout<<"Please enter the numbers:\n";
    int numbers[size];
    for (int i = 0; i < size; i++)
    {
        cin>>numbers[i];
    }
    reverseNumbers(numbers, size);
    reverseNumbersUsingStack(numbers, size);
    return 0;
}
