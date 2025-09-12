#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Tehtävä 3.  Kirjoita ohjelma, joka pyytää neljän henkilön iät ja laskee niiden kokonaissumman ja keskiarvon. */

int main()
{
    /*
    double iat[4] = {1, 2, 3, 4};

    cout << "Kirjoita iät: ";

    for (int i = 0; i < 4; i++)
    {
        cin >> iat[i];
    }
    */

    const int HENKILOITA = 4; /* Tätä numeroa voi vaihtaa niin moneen kuin haluaa */
    int iat[HENKILOITA];

    float keskiarvo, kokonaissumma = 0;
    int i;

    cout << "Kirjoita " << HENKILOITA << " henkilön iät: ";

    /* Loopataan henkilöiden läpi ja jokaseen indexiin character inputilla otetaan vasta iät */
    for (int i = 0; i < HENKILOITA; i++)
    {
        cin >> iat[i];
    }

    /* Lasketaan kokonaissumma */
    for (int ika : iat)
    {
        kokonaissumma += ika;
    }

    /* Saadan keskiarvo sillä, että jaetaan kestiarvo henkilöillä */
    keskiarvo = kokonaissumma / HENKILOITA;

    cout << "Iän keskiarvo on: " << keskiarvo << "\n";

    return 0;
}