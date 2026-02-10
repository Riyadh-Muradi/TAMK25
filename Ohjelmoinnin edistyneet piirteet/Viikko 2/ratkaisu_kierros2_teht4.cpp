#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

bool kaikki(int luku)
{
    if (luku < 2)
    {
        return false;
    }

    for (int i = 2; i < luku; i++)
    {
        if (luku % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool puolet(int luku)
{
    if (luku < 2)
    {
        return false;
    }

    for (int i = 2; i <= luku / 2; i++)
    {
        if (luku % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool juuri(int luku)
{
    if (luku < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(luku); i++)
    {
        if (luku % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    int loydettyjen_maara = 0;
    int ylaraja = 10000;

    cout << "luvut väliltä 1 - " << ylaraja << "..." << endl;

    for (int i = 1; i <= ylaraja; i++)
    {
        if (juuri(i))
        {
            cout << i << " ";
            loydettyjen_maara++;
        }
    }

    double osuus = (double)loydettyjen_maara / ylaraja * 100;

    cout << "tulokset" << endl;
    cout << "alkulukuvut: " << loydettyjen_maara << " kpl" << endl;
    cout << "kaikki:: " << osuus << " %" << endl;

    return 0;
}