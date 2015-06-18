#include <iostream>
#include <string>
#include <stack>

bool isOpen(char ch) {
    return (ch == '(') || (ch == '[') || (ch == '{') ||(ch == '<');
}

bool isClose(char ch) {
    return (ch == ')') || (ch == ']') || (ch == '}') ||(ch == '>');
}


bool isPair(char a, char b) {
    return (a == '{' && b == '}') || (a == '[' && b == ']')
        || (a == '(' && b == ')') || (a == '<' && b == '>')
        || (a == '\'' && b == '\'') || (a == '"' && b == '"');
}
bool isValidString(std::string s) 
{
    std::stack<char> open_brackets;
    bool isOpenSingleQuote = false;
    bool isOpenDoubleQuote = false;

    for( int i = 0; i < s.size(); ++i )
    {
        if( s[i] == '\'' ) {
            isOpenSingleQuote = !isOpenSingleQuote;
        }
        if( s[i] == '"' ) {
            isOpenDoubleQuote = !isOpenDoubleQuote;
        }
        if( isOpen(s[i]) || 
                (s[i] == '\'' && isOpenSingleQuote) || 
                (s[i] == '"' && isOpenDoubleQuote) ) {
            open_brackets.push(s[i]);
        } 
        if( isClose(s[i]) || 
                (s[i] == '\'' && !isOpenSingleQuote) || 
                (s[i] == '"' && !isOpenDoubleQuote) ) {
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
            std::cout << "Please input some string or press 0 to quit..." << std::endl;
        }

        else if(isValidString(s)){
            std::cout << "It's ok!" << "\nTry again..." << std::endl;
        } else {
            std::cout  << "Something is wrong!" << "\nTry again..." << std::endl;
        }
    }


	return 0;
}
