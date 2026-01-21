#include <iostream>
#include <locale>

using namespace std;

void indeksi(int t[], int koko)
{
    for (int i = 0; i < koko; i++)
    {
        t[i]++;
    }
}

void osoitin(int *t, int koko)
{
    for (int i = 0; i < koko; i++)
    {
        (*(t + i))++;
    }
}

void tulosta(int t[], int koko)
{
    for (int i = 0; i < koko; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    const int KOKO = 10;
    int taulukko[KOKO];

    for (int i = 0; i < KOKO; i++)
    {
        taulukko[i] = 0;
    }
    cout << "ennen aliohjelmaa 1: ";
    tulosta(taulukko, KOKO);

    indeksi(taulukko, KOKO);
    cout << "aliohjelma 1 jälkeen: ";
    tulosta(taulukko, KOKO);

    cout << "\n";

    for (int i = 0; i < KOKO; i++)
    {
        taulukko[i] = 0;
    }
    cout << "ennen aliohjelmaa 2: ";
    tulosta(taulukko, KOKO);

    osoitin(taulukko, KOKO);
    cout << "aliohjelma 2 jälkeen: ";
    tulosta(taulukko, KOKO);

    return 0;
}