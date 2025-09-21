#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Mikä työvuoro?" (switch--case)
Kirjoita ohjelma, joka pyytää käyttäjältä työvuoron alkamiskellonajan: klo 6: aamuvuoro, klo 14: iltavuoro, klo 22: yövuoro. Muutoin "virhetilanne". */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    int aika;

    cout << "Milloin alkaa työvuoro?: ";
    cin >> aika;

    /**
     * valitsee oikean työvuoron alkamiskellonajan perusteella.
     **/
    switch (aika)
    {
    case 6:
        cout << "Aamuvuoro";
        break;
    case 14:
        cout << "Iltavuoro";
        break;
    case 22:
        cout << "Yövuoro";
        break;
    default:
        cout << "Virhetilanne";
        break;
    }

    return 0;
}