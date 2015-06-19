#include "object_counter.h"
#include <iostream>
int Car::m_counter = 0;
Car::Car():
    m_color(""),
    m_speed(0) {
        std::cout << "Default constructor" << std::endl;
        m_counter++;
    }

Car::Car(std::string color, int speed):
    m_color(color),
    m_speed(speed) {
        std::cout << "Constructor with arguments" << std::endl;
        m_counter++;
    }

Car::Car(const Car& rhs) {
        this->setColor(rhs.m_color);
        this->setSpeed(rhs.m_speed);
        std::cout << "Copy constructor" << std::endl;
        m_counter++;
    }
void Car::Move() {
    std::cout << "The car is moving with a speed of" << m_speed << std::endl;
}

void Car::setColor(const std::string& color) {
    m_color = color;
}

std::string Car::getColor() const {
    return m_color;
}

void Car::setSpeed(const int& speed) {
    m_speed = speed;
}

int Car::getSpeed() const {
    return m_speed;
}

//int Car::getCarCount() {
//    return m_counter;
//}

Car::~Car() {
    std::cout << "Destructor" << std::endl;
    m_counter--;
}



