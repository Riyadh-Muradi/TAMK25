#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */

/*
Kirjoita ohjelma, joka:

Heittää kuusisivuista noppaa 6000 kertaa (satunnaisluku 1–6).
Tallentaa tulokset frequency[7]-taulukkoon.
Tulostaa, montako kertaa kukin silmäluku esiintyi.
    💡Vihje: käytä rand() % 6 + 1 ja srand(time(0)).
*/

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    srand(time(0));

    const int HEITOT = 6000;
    int frequency[7] = {0};

    /* Heitetään kuusisivuista noppaa 6000 kertaa */
    for (int i = 0; i < HEITOT; i++)
    {
        int luku = rand() % 6 + 1;
        frequency[luku]++;
    }

    /* Tulostetaan tulokset */
    for (int i = 1; i <= 6; i++)
    {
        cout << "Sivu " << i << ": " << frequency[i] << endl;
    }

    return 0;
    /* return EXIT_SUCCESS; */
}