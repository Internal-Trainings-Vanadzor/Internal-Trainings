#include <iostream>

class Revert {
    private:
        unsigned long long reverseTheNumber(unsigned long long num) {
            unsigned long long div = num / 10;
            if (0 == div) {
                return num;
            }
            long long result = reverseTheNumber(div);
            m_i *= 10;
            return result + num % 10 * m_i;
        }
    public:
        unsigned long long run() {
            m_i = 1;
            std::cout << "Number is " << m_number << std::endl;
            return reverseTheNumber(m_number);
        }

        unsigned long long run(const unsigned long long& num) {
            m_number = num;
            return run();
        }

        Revert(const unsigned long long& num)
            : m_number(num)
            , m_i(1)
        {}
        ~Revert()
        {}
    private:
        unsigned int m_i;
        unsigned long long m_number;
};

// Main
int main() {
    Revert obj(5432167899);
    std::cout << "V1: " << obj.run() << std::endl;
    std::cout << "V2: " << obj.run(1234567809) << std::endl;
    std::cout << "V3: " << obj.run(0) << std::endl;
    return 0;
}
