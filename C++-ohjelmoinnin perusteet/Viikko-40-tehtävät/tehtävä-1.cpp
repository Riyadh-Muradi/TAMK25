#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */

/* - luku väliltä 0-10 ja
- luku väliltä 50-100.

Ohjelma tulostaa tekstiä ja satunnaisluvut seuraavasti:
Satunnaisluvuksi väliltä 0-10 tuli ...
Satunnaisluku väliltä 50-100 tuli ... */

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    srand(time(0));

    int kymppi = rand() % 11;
    int sata = 50 + rand() % 51;

    cout << "Satunnaisluvuksi väliltä 0-10 tuli: " << kymppi << endl;
    cout << "Satunnaisluku väliltä 50-100 tuli: " << sata << endl;

    return 0;
    /* return EXIT_SUCCESS; */
}