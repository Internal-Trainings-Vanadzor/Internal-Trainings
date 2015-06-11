#include <iostream>
#include <string>
#include <stack>


//check if bracket is open returns 0,if close returns 1
int checkBracket(char c)
{
    char brackets[] = { '{', '}', '[', ']', '(', ')', '<', '>' };
    for (int i = 0; i < sizeof(brackets); ++i) {
        if (c == brackets[i] && i % 2 != 0) {
            return 1;
        } else if (c == brackets[i] && i % 2 == 0) {
            return 0;
        }
    }
    return -1;
}

bool isPair(char a, char b) {
    return (a == '{' && b == '}') || (a == '[' && b == ']')
        || (a == '(' && b == ')') || (a == '<' && b == '>');
}
bool isValidString(std::string s) 
{
    std::stack<char> open_brackets;
    
    for( int i = 0; i < s.size(); ++i )
    {
        if( checkBracket(s[i]) == 0) {
            open_brackets.push(s[i]);
        } 
        if( checkBracket(s[i]) == 1 ) {
            if(open_brackets.empty()) {
                return false;
            } else if( !isPair(open_brackets.top(), s[i]) ) {
                return false;
            } else {
                open_brackets.pop();
            }
        }
    }
    if(!open_brackets.empty()) {
        return false;
    }
    return true;
}
    
int main()
{
    std::cout << "Input a sting to check if the brackets are in their places..." << std::endl;
    std::cout << "Enter 0 to quit" << std::endl;
    std::string s;
    while(true) {
        std::getline(std::cin, s);
        if (s[0] == '0') {
            break;
        }

        if(isValidString(s)){
            std::cout << "It's ok!" << std::endl;
        } else {
            std::cout  << "Something is wrong!" << std::endl;
        }
    }


	return 0;
}
