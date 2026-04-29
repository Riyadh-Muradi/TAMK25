#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <iostream> // Add this line!

class Instrument {
private:
    std::string type, brand;
public:
    Instrument(std::string t, std::string b) : type(t), brand(b) {}
    ~Instrument() { std::cout << "Instrument destroyed" << std::endl; }
    std::string getType() const { return type; }
    std::string getBrand() const { return brand; }
    std::string toString() const { return "Instrument(" + type + ", " + brand + ")"; }
};
#endif