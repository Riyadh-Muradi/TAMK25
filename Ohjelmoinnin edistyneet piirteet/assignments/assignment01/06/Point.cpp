#include "Point.h"
#include <stdexcept>
using namespace std;

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y)
{
    if (x < 0 || y < 0)
        throw runtime_error("Negative coordinate");
}