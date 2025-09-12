#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* Bonustehtävä. Kirjoita ohjelma, joka pyytää käyttäjältä rahasumman ja korkokannan (%) ja ilmoittaa pääoman suuruuden ja koron osuuden yhden ja kahden vuoden kuluttua. Jos esim. rahasumma on 100 euroa ja korkokanta 5 %, yhden vuoden kuluttua pääoman suuruus on 105 euroa ja koron osuus 5 euroa. Kahden vuoden kuluttua pääoman suuruus on 110,25 euroa ja koron osuus 10,25 euroa. */

int main()
{
    double raha;
    double korkokanta;

    cout << "Anna rahasumma euroa: ";
    cin >> raha;

    cout << "Anna korkokanta %: ";
    cin >> korkokanta;

    /* rosentit desimaaliksi */
    korkokanta = korkokanta / 100;

    /* lasketaan korkoa */
    /* raha * pow(1 + korko, aika) */
    double vuosi1 = raha * pow(1 + korkokanta /* / 100 */, 1);
    double korko1 = vuosi1 - raha;

    cout << "Yhden vuoden kuluttua pääoma on: " << vuosi1 << " euroa" << endl;
    cout << "Koron osuus: " << korko1 << " euroa" << endl;

    /* kahen vuoden kuluttua. Luvun voi vaihtaa niin moneen vuoteen kuin haluaa */
    double vuosi2 = raha * pow(1 + korkokanta, 2);
    double korko2 = vuosi2 - raha;

    cout << "Kahden vuoden kuluttua pääoma on: " << vuosi2 << " euroa" << endl;
    cout << "Koron osuus: " << korko2 << " euroa" << endl;

    return 0;
}