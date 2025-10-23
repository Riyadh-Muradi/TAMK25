#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */
/* Harjoitus 11: Taulukon kääntö
   Kysyy käyttäjältä 10 kokonaislukua ja tallentaa ne taulukkoon.
   Tulosta kaikki arvot käänteisessä järjestyksessä (viimeinen ensin, ensimmäinen viimeiseksi).

   Vinkki: käytä for-silmukkaa ja indeksiä alkaen viimeisestä alkioon. */

int main()
{
    // TEHTÄVÄ: Toteuta ohjelma itse.

    const int LUKUJEN_MAARA = 10;
    int luvut[LUKUJEN_MAARA];

    /* Lukujen lukeminen */
    cout << "Kirjoita " << LUKUJEN_MAARA << " kokonaislukua: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
    }

    /* Lukujen tulostaminen samassa järjestyksessä */
    cout << "\nLuvut ovat: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cout << luvut[LUKUJEN_MAARA - 1 - i] << " ";
    }

    return 0;
}
