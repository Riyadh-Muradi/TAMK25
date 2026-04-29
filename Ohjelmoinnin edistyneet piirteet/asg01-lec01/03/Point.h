#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

public:
    int getX();
    bool setX(int val);
    int getY();
    void setY(int val);
};

#endif