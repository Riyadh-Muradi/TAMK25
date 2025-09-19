#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Onko kyseessä teini?" (if)
Kirjoita ohjelma, joka kysyy käyttäjältä henkilön iän ja ilmoittaa, jos kyseessä on teini eli 13-19-vuotias henkilö. Ilmoitus: "Kyseessä on teini eli teenager." */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    int ika;

    cout << "Anna ikä: ";
    cin >> ika;

    /**
     * Onko ikä välillä 13-19
     **/
    if (ika >= 13 && ika <= 19)
    {
        cout << "Kyseessä on teini eli teenager." << endl;
    }
    else
    {
        cout << "Ei ole teini." << endl;
    }

    return 0;
}