#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Tehtävä 1. Kolmion pinta-alan laskenta (liukulukujen float tai double käyttöä).

Tee ohjelma, joka laskee kolmion pinta-alan: syötteinä annetaan kanta ja korkeus. Ohjelman ajoesimerkki:

Anna kolmion kanta: 1.23

Anna kolmion korkeus: 3.9

Kolmion pinta-ala on 2.3985

Käytä kannan ja korkeuden muuttujina float- tai double –tyyppistä muuttujaa (pinta-ala: kanta*korkeus/2). */

int main()
{
    double kanta;
    double korkeus;

    cout << "Anna kolmion kanta: ";
    cin >> kanta;

    cout << "Anna kolmion korkeus: ";
    cin >> korkeus;

    /* Pinta-alan laskenta kanta * korkeus / 2 */
    cout << "Kolmion pinta-ala on: " << kanta * korkeus / 2 << endl;

    return 0;
}