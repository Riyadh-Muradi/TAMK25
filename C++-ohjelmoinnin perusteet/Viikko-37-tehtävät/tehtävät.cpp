#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

/* Tekijä: Riyadh Muradi */

void assignment1()
{
    /* Tehtävä 1 */

    double kanta;
    double korkeus;

    cout << "Anna kolmion kanta: ";
    cin >> kanta;

    cout << "Anna kolmion korkeus: ";
    cin >> korkeus;

    cout << "Kolmion pinta-ala on: " << kanta * korkeus / 2 << endl;
}

void assignment2()
{
    /* Tehtävä 2 */

    double alku;
    double prosentti;

    cout << "Syota alkuperainen hinta: ";
    cin >> alku;

    cout << "Syota aleprosentt: ";
    cin >> prosentti;

    cout << "Alennettu hinta on: " << alku - (prosentti / 100 * alku) << endl;
}

void assignment3()
{
    /* Tehtävä 3 */

    const int HENKILOITA = 4;
    int iat[HENKILOITA];

    float keskiarvo, kokonaissumma = 0;

    cout << "Kirjoita " << HENKILOITA << " henkilön iät: ";

    for (int i = 0; i < HENKILOITA; i++)
    {
        cin >> iat[i];
    }

    for (int ika : iat)
    {
        kokonaissumma += ika;
    }

    keskiarvo = kokonaissumma / HENKILOITA;

    cout << "Kokonaissumma: " << kokonaissumma << endl;
    cout << "Keskiarvo: " << keskiarvo << endl;
}

void assignment4()
{
    /* Tehtävä 4 */

    cout << "Syötä ympyrän säde: ";
    double sade;
    cin >> sade;

    const double pi = 3.14;
    double pinta = pi * pow(sade, 2);

    cout << "Ympyrän pinta-ala on: " << pinta << endl;
}

void assignment5()
{
    /* Bonustehtävä */

    double raha, korkokanta;

    cout << "Anna rahasumma euroa: ";
    cin >> raha;

    cout << "Anna korkokanta %: ";
    cin >> korkokanta;

    korkokanta = korkokanta / 100;

    double vuosi1 = raha * pow(1 + korkokanta, 1);
    double korko1 = vuosi1 - raha;

    cout << "Yhden vuoden kuluttua pääoma on: " << vuosi1 << " euroa" << endl;
    cout << "Koron osuus: " << korko1 << " euroa" << endl;

    double vuosi2 = raha * pow(1 + korkokanta, 2);
    double korko2 = vuosi2 - raha;

    cout << "Kahden vuoden kuluttua pääoma on: " << vuosi2 << " euroa" << endl;
    cout << "Koron osuus: " << korko2 << " euroa" << endl;
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    while (true)
    {
        cout << "\nValitse tehtävä:\n";
        cout << " 0) Lopeta\n";
        cout << " 1) Tehtävä 1\n";
        cout << " 2) Tehtävä 2\n";
        cout << " 3) Tehtävä 3\n";
        cout << " 4) Tehtävä 4\n";
        cout << " 5) Bonustehtävä\n";
        cout << "Valinta: ";

        int valinta = -1;
        cin >> valinta;

        switch (valinta)
        {
        case 0:
            cout << "Lopetetaan.\n";
            return 0;
        case 1:
            assignment1();
            break;
        case 2:
            assignment2();
            break;
        case 3:
            assignment3();
            break;
        case 4:
            assignment4();
            break;
        case 5:
            assignment5();
            break;
        default:
            cout << "Virheellinen valinta, yritä uudelleen.\n";
            break;
        }

        cout << "Paina Enter jatkaaksesi...";
        string tmp;
        cin.ignore();
        getline(cin, tmp);
    }

    return 0;
    /* return EXIT_SUCCESS; */
}
