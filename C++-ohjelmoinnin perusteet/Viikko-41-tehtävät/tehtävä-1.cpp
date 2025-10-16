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

Kysyy käyttäjältä 10 kokonaislukua ja tallentaa ne taulukkoon.
Tulostaa kaikki arvot samassa järjestyksessä.
Laskee ja tulostaa lukujen keskiarvon.
Vihje: käytä for-silmukkaa ja muuttujaa total summan laskemiseen.
*/

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    const int LUKUJEN_MAARA = 10;
    int luvut[LUKUJEN_MAARA];
    int kokonaisumma = 0;

    /* Lukujen lukeminen */
    cout << "Kirjoita " << LUKUJEN_MAARA << " kokonaislukua: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
        kokonaisumma += luvut[i]; /* Lisätään luku summaan */
    }

    /* Lukujen tulostaminen samassa järjestyksessä */
    cout << "\nLuvut ovat: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cout << luvut[i] << " ";
    }

    /* Keskiarvon laskeminen ja tulostaminen */
    double keskiarvo = (double)kokonaisumma / LUKUJEN_MAARA;
    cout << "\nLukujen summa: " << kokonaisumma << endl;
    cout << "Lukujen keskiarvo: " << keskiarvo << endl;

    return 0;
    /* return EXIT_SUCCESS; */
}