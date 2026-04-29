#include "Phone.h"

Phone::Phone(std::string m, int cap) : model(m)
{
    battery = new Battery(cap);
}
Phone::~Phone()
{
    delete battery;
}
Phone::Phone(const Phone &other) : model(other.model)
{
    std::cout << "Copy constructor called" << std::endl;
    battery = new Battery(other.battery->getCapacity());
}
Phone &Phone::operator=(const Phone &other)
{
    std::cout << "Copy assignment called" << std::endl;
    if (this != &other)
    {
        delete battery;
        model = other.model;
        battery = new Battery(other.battery->getCapacity());
    }
    return *this;
}
std::string Phone::getModel() const { return model; }
int Phone::getBatteryCapacity() const { return battery->getCapacity(); }
void Phone::setBatteryCapacity(int cap)
{
    delete battery;
    battery = new Battery(cap);
}
std::string Phone::toString() const
{
    return "Phone(" + model + ", " + battery->toString() + ")";
}
std::ostream &operator<<(std::ostream &os, const Phone &p)
{
    os << p.toString();
    return os;
}