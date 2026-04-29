#ifndef HUMAN_H
#define HUMAN_H
#include "Heart.h"
#include "Car.h"
#include <iostream>

class Human
{
private:
    std::string name;
    Heart heart;
    const Car *car;

public:
    Human(std::string n, int bpm);
    void setCar(const Car *c);
    std::string toString() const;
    friend std::ostream &operator<<(std::ostream &os, const Human &h);
};
#endif