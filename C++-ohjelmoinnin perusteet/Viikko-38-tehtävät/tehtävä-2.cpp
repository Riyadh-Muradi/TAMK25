#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/*  "Mahdutaanko hissiin?" (if--else)
Kirjoita ohjelma, johon esittelet hissin painorajan vakiona. Ohjelma kysyy käyttäjältä neljän eri henkilön painot.
Jos painot ovat yhteensä yli hissin painorajan, tulee ilmoitus: "Ei lupaa hissiin, painoraja ylittyy." Jos painoraja ei ylity, tulee ilmoitus: "Astukaa hissiin.". */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    const int HENKILOIDEN = 4; /* Tätä numeroa voi vaihtaa niin moneen kuin haluaa */
    int painot[HENKILOIDEN];

    const int painoRaja = 600;

    cout << "Kirjoita " << HENKILOIDEN << " Henkilöiden painot: ";

    int summa = 0;
    /**
     * Lasketaan kaikkien henkilöiden painojen summa
     **/
    for (int i = 0; i < HENKILOIDEN; i++)
    {
        cin >> painot[i];
        summa += painot[i];
    }

    /**
     * Tarkistetaan ylittyykö hissin painoraja
     **/
    if (summa > painoRaja)
    {
        cout << "Ei lupaa hissiin, painoraja ylittyy.";
    }
    else
    {
        cout << "Astukaa hissiin.";
    }

    return 0;
}