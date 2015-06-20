#include<iostream>
#include <math.h>  

int reversion(int num);
int reversion_recursion(int num);

int main()
{
	int num;
	std::cout << ">>>>> This is number reversion programm. <<<<<" << std::endl;
	std::cin >> num;
	
	std::cout << "Reversion of the number equals:" << reversion(num) << std::endl;  
	std::cout << "ReversionRecursion of the number equals:" << reversion_recursion(num) << std::endl;

	system("pause");
	return 0;
}

int reversion(int num)
{
	int rev = 0;
	while (0 != num)
	{
		rev = rev * 10 + num % 10;
		std::cout << "Reversion of the number step by step equals: " << rev << std::endl;
		num = num /10;
	}
	return rev;
}

int reversion_recursion(int num)
{
  static int rev = 0;
  static int count = 1;
  if(num > 0)
  {
    reversion_recursion(num/10);
    rev = rev + (num%10)*count;
    count = count * 10;
  }
  return rev;
}