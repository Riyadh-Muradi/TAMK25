#ifndef MUSICIAN_H
#define MUSICIAN_H
#include "Name.h"
#include "Instrument.h"
#include "Studio.h"
#include <iostream>

class Musician {
private:
    Name name;
    Instrument* instrument;
    const Studio* studio;
public:
    Musician(std::string f, std::string l, std::string iT, std::string iB);
    ~Musician();
    Musician(const Musician& other);
    Musician& operator=(const Musician& other);
    void setStudio(const Studio* s);
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Musician& m);
};
#endif