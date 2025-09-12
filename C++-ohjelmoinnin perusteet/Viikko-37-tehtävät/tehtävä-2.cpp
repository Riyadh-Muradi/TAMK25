#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Tehtävä 2. Ale-ohjelma. Tee ohjelma, joka kysyy käyttäjältä tuotteen alkuperäisen hinnan ja alennusprosentin. Ohjelma tulostaa alennetun hinnan. Ohjelman ajoesimerkki:

Syota alkuperainen hinta (euroa): 119

Syota aleprosentti: 40

Alennettu hinta on: 71.40 euroa. */

int main()
{

    double alku;
    double prosentti;

    cout << "Syota alkuperainen hinta:";
    cin >> alku;

    cout << "Syota aleprosentt: ";
    cin >> prosentti;

    /* Alennettun hinnan laskenta alkuhinta - (alkuhinta * ale%) */
    cout << "Alennettu hinta on: " << alku - (prosentti / 100 * alku);

    return 0;
}