#include <iostream>
#include <locale>

using namespace std;

void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    const int KOKO = 10;
    int taulukko[KOKO];

    for (int i = 0; i < KOKO; i++)
    {
        taulukko[i] = i + 1;
    }

    for (int i = 0; i < KOKO / 2; i++)
    {

        swap2((taulukko + i), (taulukko + (KOKO - 1 - i)));
    }

    cout << "käänetty: ";
    for (int i = 0; i < KOKO; i++)
    {
        cout << taulukko[i] << " ";
    }
    cout << endl;

    return 0;
}