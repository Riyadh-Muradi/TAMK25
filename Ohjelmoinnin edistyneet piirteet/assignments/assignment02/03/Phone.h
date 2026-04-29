#ifndef PHONE_H
#define PHONE_H
#include "Battery.h"
#include <iostream>

class Phone
{
private:
    std::string model;
    Battery *battery;

public:
    Phone(std::string m, int cap);
    ~Phone();
    Phone(const Phone &other);
    Phone &operator=(const Phone &other);
    std::string getModel() const;
    int getBatteryCapacity() const;
    void setBatteryCapacity(int cap);
    std::string toString() const;
    friend std::ostream &operator<<(std::ostream &os, const Phone &p);
};
#endif