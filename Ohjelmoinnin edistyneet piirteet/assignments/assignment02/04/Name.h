#ifndef NAME_H
#define NAME_H
#include <string>

class Name
{
private:
    std::string first, last;

public:
    Name(std::string f, std::string l) : first(f), last(l) {}
    std::string toString() const { return "Name(" + first + ", " + last + ")"; }
};
#endif  