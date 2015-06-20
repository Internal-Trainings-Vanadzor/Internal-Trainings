#include <iostream>
#include <string>
#include <stack>

bool check_brackets(std::string);
bool isMatchingPair(char, char);

int main()
{
	std::string str;
	std::cout << ">>>>> Hello this is brackets checker programm <<<<<" << std::endl;
	std::cout << "Please enter the string expression: " << std::endl;
	std::getline(std::cin,str);
	
	if (check_brackets(str))
	{
		std::cout << "Your expression is correct." << std::endl;
	} else {
		std::cout << "Your expression is not correct." << std::endl;
	}

	system("pause");

	return 0;
}
//This function is matching the brackets pairs.
bool MatchingBracketPairs(char open_bracket, char close_bracket)
{
   if(open_bracket == '(' && close_bracket == ')')
     return 1;
   else if(open_bracket == '{' && close_bracket == '}')
     return 1;
   else if(open_bracket == '[' && close_bracket == ']')
     return 1;
   else
     return 0;
}
//The check_brackets function is checking for balanced parentheses in an expression.
bool check_brackets(const std::string str)
{	
	int double_quotation_marks_count = 0;
	int single_quotation_marks_count = 0;
	std::stack<char> my_stack;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		//If str[0] is an ending parenthesis then return from function.  
		if (*(str.begin()) == '}' || *(str.begin()) == ']' || *(str.begin()) == ')')
		{
			return false;
		}
		/*If the double_quotation_marks_count is odd push it, otherwise check if stack is empty and 
		is top of the stack double quotation mark then pop it from stack.*/
		else if (*it == '"')
		{
			++double_quotation_marks_count; 
			if (double_quotation_marks_count%2 != 0)
			{
				my_stack.push(*it);
			} else {
				if(my_stack.empty() || my_stack.top() != '"')
				{
					return false;
				} else {
					my_stack.pop();
				}
			}
		}
		/*If the single_quotation_marks_count is odd push it, otherwise check if stack is empty and 
		is top of the stack single quotation mark then pop it from stack.*/
		else if (*it == '\'')
		{
			++single_quotation_marks_count; 
			if (single_quotation_marks_count%2 != 0)
			{
				my_stack.push(*it);
			} else {
				if(my_stack.empty() || my_stack.top() != '\'')
				{
					return false;
				} else {
					my_stack.pop();
				}
			}
		}
		//If the str[i] is a starting parenthesis then push it.
		else if (*it == '{' || *it == '(' || *it == '[')
		{
			my_stack.push(*it);
		}
		//If str[i] is a ending parenthesis then check if the stack is empty and the parenthesis is a matching pair and pop from stack.
		else if (*it == '}' || *it == ')' || *it == ']')
		{
			if (my_stack.empty() || !MatchingBracketPairs(my_stack.top(),*it))
			 {
				return false;
			 } else {				 
				my_stack.pop();
			 }
		}
	}	
	//The function returns true if the stack is empty and false otherwise.
	return my_stack.empty();
}
		