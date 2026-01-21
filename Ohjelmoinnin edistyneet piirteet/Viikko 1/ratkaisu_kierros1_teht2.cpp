#include <iostream>
#include <locale>

using namespace std;

void swap1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    int yksi = 1;
    int kaksi = 2;
    cout << "yksi = " << yksi << ", kaksi = " << kaksi << " ennen swap1:ia." << endl;

    swap1(yksi, kaksi);

    cout << "yksi = " << yksi << ", kaksi = " << kaksi << " jölkeen swap1:in." << endl;

    int kolme = 3;
    int nelja = 4;
    cout << "kolme = " << kolme << ", nelja = " << nelja << " ennen swap2:ia." << endl;

    swap2(&kolme, &nelja);

    cout << "kolme = " << kolme << ", nelja = " << nelja << " jölkeen swap2:in." << endl;

    return 0;
}