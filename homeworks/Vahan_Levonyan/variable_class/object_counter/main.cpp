#include "object_counter.h"
#include <iostream>
#include <string>
void drawCar(Car c, std::string color) {
    c.setColor(color);
}
int main() {
    Car Jori;
    Car Opel;
    Car Mersedec;
    drawCar(Mersedec, "grey");
    std::cout << "There are " << Car::getCarCount() << "cars created" << std::endl;

    return 0;
}
