#include <iostream>
#include <string>
#include <stack>

bool isOpen(char ch) {
    return (ch == '(') || (ch == '[') || (ch == '{') ||(ch == '<');
}

bool isClose(char ch) {
    return (ch == ')') || (ch == ']') || (ch == '}') ||(ch == '>');
}

bool isQuote(char ch) {
    return (ch == '\'') || (ch == '"');
}

bool isPair(char a, char b) {
    return (a == '{' && b == '}') || (a == '[' && b == ']')
        || (a == '(' && b == ')') || (a == '<' && b == '>')
        || (a == '\'' && b == '\'') || (a == '"' && b == '"');
}
bool isValidString(std::string s) 
{
    std::stack<char> open_brackets;
    bool isOpenQuote = true;
    for( int i = 0; i < s.size(); ++i )
    {
        if( isQuote(s[i]) ) {
            if(open_brackets.empty()) {
                isOpenQuote = true;
            }
            else if(!isPair(open_brackets.top(), s[i])) {
                isOpenQuote = true;
            }
            else {
                isOpenQuote = false;
            }
        }
        if( isOpen(s[i]) || (isQuote(s[i]) && isOpenQuote == true) ) {
            open_brackets.push(s[i]);
        } 
        if( isClose(s[i]) || (isQuote(s[i]) && isOpenQuote == false) ) {
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
        else if (s[0] == '\0') {
            std::cout << "Please input some string..." << std::endl;
        }

        else if(isValidString(s)){
            std::cout << "It's ok!" << "\nTry again..." << std::endl;
        } else {
            std::cout  << "Something is wrong!" << "\nTry again..." << std::endl;
        }
    }


	return 0;
}
