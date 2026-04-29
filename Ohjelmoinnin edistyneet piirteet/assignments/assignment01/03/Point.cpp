#include "Point.h"
#include <stdexcept>
using namespace std;

int Point::getX() { return x; }
bool Point::setX(int val)
{
    if (val < 0)
        return false;
    x = val;
    return true;
}
int Point::getY() { return y; }
void Point::setY(int val)
{
    if (val < 0)
        throw runtime_error("Negative value");
    y = val;
}