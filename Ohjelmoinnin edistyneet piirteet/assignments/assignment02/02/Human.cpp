#include "Human.h"

Human::Human(std::string n, int bpm) : name(n), heart(bpm), car(nullptr) {}
void Human::setCar(const Car *c) { car = c; }
std::string Human::toString() const
{
    std::string carStr = car ? car->toString() : "no car";
    return "Human(" + name + ", " + heart.toString() + ", " + carStr + ")";
}
std::ostream &operator<<(std::ostream &os, const Human &h)
{
    os << h.toString();
    return os;
}