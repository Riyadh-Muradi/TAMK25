#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Tehtävä 4. Kirjoita ohjelma, joka kysyy käyttäjältä ympyrän säteen ja ilmoittaa sen pinta-alan. Esittele muuttujaluettelon tai koko pääohjelman eteen vakio pii seuraavasti:
const double pii=3.141592654; */

int main()
{
    cout << "Syötä ympyrän sädettä: ";
    double sade;
    cin >> sade;

    const double pi = 3.14;
    /* Pinta-alan laskenta: pi * säde^2 */
    double pinta = pi * pow(sade, 2);

    cout << pinta;

    return 0;
}