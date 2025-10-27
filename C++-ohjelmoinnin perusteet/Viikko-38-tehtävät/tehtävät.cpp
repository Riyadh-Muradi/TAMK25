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
    int ika;

    cout << "Anna ikä: ";
    cin >> ika;

    if (ika >= 13 && ika <= 19)
    {
        cout << "Kyseessä on teini eli teenager." << endl;
    }
    else
    {
        cout << "Ei ole teini." << endl;
    }
}

void assignment2()
{
    /* Tehtävä 2 */
    const int HENKILOIDEN = 4;
    int painot[HENKILOIDEN];

    const int painoRaja = 600;

    cout << "Kirjoita " << HENKILOIDEN << " Henkilöiden painot: ";

    int summa = 0;
    for (int i = 0; i < HENKILOIDEN; i++)
    {
        cin >> painot[i];
        summa += painot[i];
    }

    if (summa > painoRaja)
    {
        cout << "Ei lupaa hissiin, painoraja ylittyy.";
    }
    else
    {
        cout << "Astukaa hissiin.";
    }
}

void assignment3()
{
    /* Tehtävä 3 */
    int U, P, A;

    cout << "Anna jännite (U): ";
    cin >> U;

    cout << "Anna laitteen teho (P): ";
    cin >> P;

    cout << "Anna sulakkeen koko (A): ";
    cin >> A;

    double I = P / U;
    cout << "Laitteen käyttämä virta: " << I << " A" << endl;

    if (I <= A)
    {
        cout << "Sulake riittää. Laitteen voi kytkeä pistorasiaan.";
    }
    else
    {
        cout << "Sulake ei riitä! Laitetta ei voi kytkeä.";
    }
}

void assignment4()
{
    /* Tehtävä 4 */
    int aika;

    cout << "Milloin alkaa työvuoro?: ";
    cin >> aika;

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
