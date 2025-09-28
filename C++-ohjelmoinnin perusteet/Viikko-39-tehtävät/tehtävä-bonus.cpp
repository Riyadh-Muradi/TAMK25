#include <iostream>
#include <cmath>
#include <string>
#include <locale>

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
    setlocale(LC_ALL, "fi_FI.UTF-8");

    const int TUOMAREITA = 5;
    string uudelleen;

    do
    {
        double pisteet[TUOMAREITA];
        double summa = 0;
        double pituus, maxPisteet, minPisteet;

        cout << "Anna hypyn pituus, metriä: ";
        cin >> pituus;

        /**
         * Kysytään tuomareiden tyylipisteet ja lasketaan summa
         **/
        for (int i = 0; i < TUOMAREITA; i++)
        {
            cout << "Anna " << (i + 1) << ". tuomarin tyylipisteet: ";
            cin >> pisteet[i];
            summa += pisteet[i];
        }

        /**
         * Etsitään suurin ja pienin tyylipiste
         **/
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
         * Lasketaan kokonaispisteet ilman suurinta ja pienintä tyylipistettä
         **/
        double tyyliPisteet = summa - maxPisteet - minPisteet;
        double kokonaisPisteet = tyyliPisteet + 0.9 * pituus;

        cout << "Hypyn kokonaispisteet: " << kokonaisPisteet << endl;

        cout << "Uudelleen (k/e)? ";
        cin >> uudelleen;

    } while (uudelleen == "k" || uudelleen == "K");

    return 0;
}