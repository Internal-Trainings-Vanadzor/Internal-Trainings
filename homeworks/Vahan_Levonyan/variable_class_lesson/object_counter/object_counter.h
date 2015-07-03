#include <string>

class Car {
    public:
        Car();
        Car(std::string, int);
        Car(const Car&);
        ~Car();
        void Move();
        void setColor(const std::string&);
        std::string getColor() const;
        void setSpeed(const int&);
        int getSpeed() const;
        static inline int getCarCount() { return m_counter; } 
    private:
        std::string m_color;
        int m_speed;
        static int m_counter;
};




