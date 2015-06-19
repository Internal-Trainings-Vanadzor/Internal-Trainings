#include <iostream>

using namespace std;

static int reverseNumber(int number)
{
    static int revNumber = 0;
    if (number == 0 )
    {
        return revNumber;
    }
    revNumber = revNumber*10 + number%10;
    reverseNumber(number/10);
}
int main()
{
    int input_number;
    cout << "Enter an integer number" << endl;
    cin >> input_number;
    cout << "Reverse number will be" << endl;
    cout << reverseNumber(input_number) << endl;
    
    return 0;
}


