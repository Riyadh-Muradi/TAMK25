#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* 5. BONUSTEHTÄVÄ. Tee ohjelma, joka laskee mäkihyppääjälle pisteet. Mäkihypyssä on viisi arvostelutuomaria. Ohjelma kysyy hypyn pituuden sekä arvostelutuomareiden hyppääjälle antamat tyylipisteet. Lopuksi ohjelma tulostaa hyppääjän saaman pistemäärän: tyylipisteet + 0,9*hypyn pituus. Lopussa ohjelma kysyy: "Uudelleen (k/e)?".
Hypyn pituus ja kunkin eri tuomarin antamat tyylipisteet kysytään seuraavasti:

Anna hypyn pituus, metriä:

Anna 1. tuomarin tyylipisteet:

Anna 2. tuomarin tyylipisteet:

Anna 3. tuomarin tyylipisteet:

Anna 4. tuomarin tyylipisteet:

Anna 5. tuomarin tyylipisteet: */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    const int TUOMAREITA = 5;
    double pisteet[TUOMAREITA];
    double summaPisteet = 0;
    double pituus, maxPisteet, minPisteet;

    cout << "Anna hypyn pituus, metriä: ";
    cin >> pituus;

    /**
     * Kysytään tuomareiden pisteet ja lasketaan summa
     */
    for (int i = 0; i < TUOMAREITA; i++)
    {
        cout << "Anna " << (i + 1) << ". tuomarin tyylipisteet: ";
        cin >> pisteet[i];
        summaPisteet += pisteet[i];
    }

    /**
     * Etsitään suurin ja pienin piste
     */
    maxPisteet = pisteet[0];
    minPisteet = pisteet[0];
    for (int i = 1; i < TUOMAREITA; i++)
    {
        if (pisteet[i] > maxPisteet)
            maxPisteet = pisteet[i];
        if (pisteet[i] < minPisteet)
            minPisteet = pisteet[i];
    }

    /**
     * Lasketaan kokonaispisteet ilman suurinta ja pienintä
     */
    double pisteetIlmanAarempia = summaPisteet - maxPisteet - minPisteet;
    double kokonaisPisteet = pisteetIlmanAarempia + 0.9 * pituus;

    cout << "Hypyn kokonaispisteet (ilman suurinta ja pienintä): " << kokonaisPisteet << endl;

    return 0;
}