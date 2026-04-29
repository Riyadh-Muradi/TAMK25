#include "Line.h"
#include <cmath>

Line::Line(Point s, Point e) : start(s), end(e) {}
Point Line::getStart() const { return start; }
Point Line::getEnd() const { return end; }
double Line::length() const
{
    return std::sqrt(std::pow(end.getX() - start.getX(), 2) + std::pow(end.getY() - start.getY(), 2));
}
void Line::moveBy(int dx, int dy)
{
    start.setX(start.getX() + dx);
    start.setY(start.getY() + dy);
    end.setX(end.getX() + dx);
    end.setY(end.getY() + dy);
}
std::string Line::toString() const
{
    return "Line(" + start.toString() + ", " + end.toString() + ")";
}
std::ostream &operator<<(std::ostream &os, const Line &l)
{
    os << l.toString();
    return os;
}