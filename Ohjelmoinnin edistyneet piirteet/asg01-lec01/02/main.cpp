#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point p;
    cout << p.x << " " << p.y << endl;
    p.x = 10;
    p.y = 20;
    cout << p.x << " " << p.y << endl;

    Point *hp = new Point();
    cout << hp->x << " " << hp->y << endl;
    cout << hp << endl;

    (*hp).x = 30;
    hp->y = 40;
    cout << hp->x << " " << hp->y << endl;

    delete hp;
    return 0;
}