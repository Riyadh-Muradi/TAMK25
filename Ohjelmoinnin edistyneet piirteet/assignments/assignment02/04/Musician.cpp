#include "Musician.h"

Musician::Musician(std::string f, std::string l, std::string iT, std::string iB)
    : name(f, l), studio(nullptr)
{
    instrument = new Instrument(iT, iB);
}

Musician::~Musician()
{
    delete instrument;
}

Musician::Musician(const Musician &other) : name(other.name), studio(other.studio)
{
    instrument = new Instrument(other.instrument->getType(), other.instrument->getBrand());
}

Musician &Musician::operator=(const Musician &other)
{
    if (this != &other)
    {
        delete instrument;
        name = other.name;
        studio = other.studio;
        instrument = new Instrument(other.instrument->getType(), other.instrument->getBrand());
    }
    return *this;
}

void Musician::setStudio(const Studio *s) { studio = s; }

std::string Musician::toString() const
{
    std::string sInfo = studio ? studio->toString() : "no studio";
    return name.toString() + ", " + instrument->toString() + ", " + sInfo;
}

std::ostream &operator<<(std::ostream &os, const Musician &m)
{
    os << m.toString();
    return os;
}