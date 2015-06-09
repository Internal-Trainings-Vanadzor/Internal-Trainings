#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

const std::string statment= "{}[]\"\'";

class Checker {
private:
    std::map<char,char> m_convertor;
    std::vector<char> m_stack;
    std::string m_check_string;

public:
    bool check() {
        for(int i = 0; i < m_check_string.size(); ++i ) {
            //std::cout << "m_check_string " << i << " " << m_check_string[i] << std::endl; 
            if (statment.find(m_check_string[i]) == std::string::npos) {
                continue;
            }
            if(!isCorrectStatement(m_check_string[i])) {
                std::cout << "The string is not valid from " << i << " position: " << m_check_string << std::endl;
                return false;
            }
        }
        std::cout << "Congradulation :) The string is valid: " << m_check_string << std::endl;
    }

    bool isCorrectStatement(char sym) {
        if(!m_convertor[sym]) {
            m_stack.push_back(sym);
            return true;
        }
        if (m_stack.back() != sym) {
            if (('\'' == sym) || ('\"' == sym)) {
                m_stack.push_back(sym);
                return true;
            }
        }
        if (m_stack.back() != m_convertor[sym]) {
            return false;
        } else {
            m_stack.pop_back();
            return true;
        }
    }

    void setCheckingString(std::string str) {
        m_check_string = str;
    }

    // Condtuctore
    Checker(std::string checkString="") {
        m_check_string = checkString; 
        m_convertor['}'] ='{';
        m_convertor[']'] ='[';
        m_convertor[')'] ='(';
        m_convertor['\''] ='\'';
        m_convertor['\"'] ='\"';
    }
};

int main() {
    // postive test
    Checker test("{{}}");
    test.check();
    test.setCheckingString("[]{}[]");
    test.check();
    test.setCheckingString("\"\'{[(TUX)]}\'\"");
    test.check();

    // negative test
    test.setCheckingString("{{{{[[}");
    test.check();
    test.setCheckingString("}{");
    test.check();
    return 0;
}
