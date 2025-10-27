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
    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    int i = luku;
    while (i >= -luku)
    {
        cout << i << " ";
        i--;
    }
    cout << endl;
}

void assignment2()
{
    /* Tehtävä 2 */
    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    for (int i = luku; i >= -luku; i--)
    {
        cout << i << " ";
    }
    cout << endl;
}

void assignment3()
{
    /* Tehtävä 3a */
    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    int i = 1;
    do
    {
        if (i % 2 == 0)
            cout << i << " ";
        i++;
    } while (i <= luku);

    cout << endl;
}

void assignment4()
{
    /* Tehtävä 4 */
    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    for (int i = 2; i <= luku; i++)
    {
        if (i % 2 == 0)
            cout << i << " ";
    }
    cout << endl;
}

void assignment5()
{
    /* Bonustehtävä */
    const int TUOMAREITA = 5;
    string uudelleen;

    do
    {
        double pisteet[TUOMAREITA];
        double summa = 0;
        double pituus, maxPisteet, minPisteet;

        cout << "Anna hypyn pituus, metriä: ";
        cin >> pituus;

        for (int i = 0; i < TUOMAREITA; i++)
        {
            cout << "Anna " << (i + 1) << ". tuomarin tyylipisteet: ";
            cin >> pisteet[i];
            summa += pisteet[i];
        }

        maxPisteet = pisteet[0];
        minPisteet = pisteet[0];
        for (int i = 1; i < TUOMAREITA; i++)
        {
            if (pisteet[i] > maxPisteet)
                maxPisteet = pisteet[i];
            if (pisteet[i] < minPisteet)
                minPisteet = pisteet[i];
        }

        double tyyliPisteet = summa - maxPisteet - minPisteet;
        double kokonaisPisteet = tyyliPisteet + 0.9 * pituus;

        cout << "Hypyn kokonaispisteet: " << kokonaisPisteet << endl;

        cout << "Uudelleen (k/e)? ";
        cin >> uudelleen;

    } while (uudelleen == "k" || uudelleen == "K");
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
