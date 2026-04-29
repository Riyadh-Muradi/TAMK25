#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

public:
    int getX() const;
    int getY() const;
    void setX(int val);
    void setY(int val);
};

#endif