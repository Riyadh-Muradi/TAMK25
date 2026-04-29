#ifndef BATTERY_H
#define BATTERY_H
#include <string>

class Battery
{
private:
    int capacityMah;

public:
    Battery(int cap) : capacityMah(cap) {}
    int getCapacity() const { return capacityMah; }
    std::string toString() const
    {
        return "Battery(" + std::to_string(capacityMah) + " mAh)";
    }
};
#endif