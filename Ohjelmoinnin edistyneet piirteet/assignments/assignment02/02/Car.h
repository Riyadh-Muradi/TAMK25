#ifndef CAR_H
#define CAR_H
#include <string>

class Car {
private:
    std::string brand, model;
public:
    Car(std::string b, std::string m) : brand(b), model(m) {}
    std::string toString() const {
        return "Car(" + brand + ", " + model + ")";
    }
};
#endif