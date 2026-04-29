#include "Point.h"
#include <stdexcept>
using namespace std;

void Point::setX(int val)
{
    if (val < 0)
        throw runtime_error("Negative X");
    x = val;
}
void Point::setY(int val)
{
    if (val < 0)
        throw runtime_error("Negative Y");
    y = val;
}
void Point::moveBy(int dx, int dy)
{
    setX(x + dx);
    setY(y + dy);
}