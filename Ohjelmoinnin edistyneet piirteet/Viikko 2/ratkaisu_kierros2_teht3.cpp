#include <iostream>
#include <locale>

using namespace std;

int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int min(int x, int y, int z, int w)
{
    return min(min(x, y, z), w);
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    cout << "pienin (10, 5): " << min(10, 5) << endl;
    cout << "pienin (8, 12, 3): " << min(8, 12, 3) << endl;
    cout << "pienin (15, 7, 20, 4): " << min(15, 7, 20, 4) << endl;

    return 0;
}