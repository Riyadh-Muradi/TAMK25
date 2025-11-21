#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

/* Tekijä: Riyadh Muradi */

void tulostaMerkki(char merkki, int lukumaara)
{
    for (int i = 0; i < lukumaara; i++)
    {
        cout << merkki;
    }
    cout << endl;
}

void laskeKertoma(int n)
{
    if (n < 0)
    {
        cout << "Error\n";
        return;
    }

    int vastaus = 1;
    for (int i = 1; i <= n; i++)
    {
        vastaus = vastaus * i;
    }
    cout << vastaus << endl;
}

void laskeTilavuus(int korkeus, int leveys, int syvyys)
{
    int lasku = korkeus * leveys * syvyys;
    cout << lasku << endl;
}

void assignment1()
{
    /* Tehtävä 1 */
    char merkki;
    int lukumaara;

    cout << "Kirjoita lukumäärä: ";
    cin >> lukumaara;
    cout << "Kirjoita merkki: ";
    cin >> merkki;

    tulostaMerkki(merkki, lukumaara);
}

void assignment2()
{
    /* Tehtävä 2 */
    int num;
    cout << "Kirjoita numero: ";
    cin >> num;

    laskeKertoma(num);
}

void assignment3()
{
    /* Tehtävä 3 */
    int korkeus, leveys, syvyys;
    cout << "Anna arvot: ";
    cin >> korkeus >> leveys >> syvyys;

    laskeTilavuus(korkeus, leveys, syvyys);
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
