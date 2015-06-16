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
            if (statment.find(m_check_string[i]) == std::string::npos) {
                continue;
            }
            if(!isCorrectStatement(m_check_string[i])) {
                std::cout << "The string is not valid from " << i 
                    << " position: " << m_check_string << std::endl;
                return false;
            }
        }
        if (!m_stack.empty()) {
            std::cout << "The string is not valid: some open tags haven't "
                << " close tags." << m_check_string << std::endl;
            return false;
        }
        std::cout << "Congradulation :) The string is valid: " 
            << m_check_string << std::endl;
        return true;
    }

    bool isCorrectStatement(char sym) {
        std::map<char,char>::iterator it = m_convertor.find(sym);
        if(it == m_convertor.end()) {
            m_stack.push_back(sym);
            return true;
        }
        if (('\'' == sym) || ('\"' == sym)) {
            if (m_stack.empty()) {
                m_stack.push_back(sym);
                return true;
            }
            if (m_stack.back() != sym) {
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
        m_stack.clear();
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
    test.setCheckingString("\"a\"");
    test.check();
    test.setCheckingString("{\'\'}");
    test.check();

    // negative test
    test.setCheckingString("{{{{[[}");
    test.check();
    test.setCheckingString("}{");
    test.check();
    test.setCheckingString("{}{");
    test.check();
    test.setCheckingString("\"");
    test.check();
    test.setCheckingString("{{{");
    test.check();
    return 0;
}
