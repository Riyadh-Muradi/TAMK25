#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/* Tekijä: Riyadh Muradi */

/* 2. Kirjoita ohjelma, joka arpoo satunnaislukuja kahden desimaalin tarkkuudella seuraavasti:
- luku väliltä 0-1 ja
- luku väliltä 0,5-1. */

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    srand(time(0));

    /*  Väliltä 0–1: arvotaan kokonaisluku [0,100] ja jaetaan sadalla */
    int x0_100 = rand() % 101;
    double valilta0_1 = x0_100 / 100.0;

    /* Väliltä 0,5–1: arvotaan kokonaisluku [50,100] ja jaetaan sadalla */
    int x50_100 = 50 + rand() % 51;
    double valilta05_1 = x50_100 / 100.0;

    cout << fixed << setprecision(2);
    cout << "Satunnaisluku väliltä 0-1: " << valilta0_1 << endl;
    cout << "Satunnaisluku väliltä 0,5-1: " << valilta05_1 << endl;

    return 0;
    /* return EXIT_SUCCESS; */
}