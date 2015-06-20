#include <iostream>
#include <stack>
#include <string>

/**
 * This functions checks whether two given chars are pair of brackets.
 */
bool are_correct_brackets (char left, char right) {
    return left == '{' && right == '}' or 
        left == '(' && right == ')' or 
        left == '"' && right == '"' or 
        left == '\'' && right == '\'' or 
        left == '[' && right == ']';
}

/**
 * This functions checks if the brackets of the given expression are correct.
 */
bool is_correct_expression (const std::string& expression) {
    std::stack<char> left;
    bool single_quote_added = false;
    bool double_quote_added = false;
    for(int i = 0; i < expression.size(); ++i) {
        char el = expression[i];
        switch(el) {
            case '{': case '(': case '[':
                left.push(el);
                break;
            case '}': case ')': case ']':
                if (left.empty() || !are_correct_brackets(left.top(), el)) {
                    return false;
                }
                left.pop();
                break;
             case '"': case '\'':
                bool* checker;
                if ('\'' == el) {
                    checker = &single_quote_added;
                } else {
                    checker = &double_quote_added;
                }
                if (left.empty() || !are_correct_brackets(left.top(), el)) {
                    if (*checker) {
                        return false;
                    } else {
                        left.push(el);
                        *checker = true;
                    }
                } else {
                    left.pop();
                    *checker = false;
                }
                break;
        }
    }
    return left.empty();
}

int main () {
    std::string expression;
    std::cout << "Please input the expression and press Enter:\n";
    std::cin >> expression;
    if (is_correct_expression (expression)) {
        std::cout << expression << " is correct. Bye :)" << std::endl;
    } else {
        std::cout << expression << " is incorrect. Bye :(" << std::endl;
    }
    return 0;
}
