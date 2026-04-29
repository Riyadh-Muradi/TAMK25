#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include <iostream>

class Line
{
private:
    Point start, end;

public:
    Line(Point s, Point e);
    Point getStart() const;
    Point getEnd() const;
    double length() const;
    void moveBy(int dx, int dy);
    std::string toString() const;
    friend std::ostream &operator<<(std::ostream &os, const Line &l);
};
#endif