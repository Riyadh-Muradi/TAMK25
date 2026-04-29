#ifndef STUDIO_H
#define STUDIO_H
#include <string>

class Studio
{
private:
    std::string name, city;

public:
    Studio(std::string n, std::string c) : name(n), city(c) {}
    std::string getName() const { return name; }
    std::string getCity() const { return city; }
    std::string toString() const { return "Studio(" + name + ", " + city + ")"; }
};
#endif