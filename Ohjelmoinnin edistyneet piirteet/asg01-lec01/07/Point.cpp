#include "Point.h"
#include <string>
#include <iostream>
using namespace std;

string Point::toString() const
{
    return "Point(" + to_string(x) + ", " + to_string(y) + ")";
}
ostream &operator<<(ostream &os, const Point &p)
{
    os << p.toString();
    return os;
}
bool Point::operator==(const Point &other) const
{
    return x == other.x && y == other.y;
}
Point Point::operator+(const Point &other) const
{
    return Point(x + other.x, y + other.y);
}