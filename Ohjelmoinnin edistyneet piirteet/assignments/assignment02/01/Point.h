#ifndef POINT_H
#define POINT_H
#include <string>

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }
    std::string toString() const
    {
        return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};
#endif