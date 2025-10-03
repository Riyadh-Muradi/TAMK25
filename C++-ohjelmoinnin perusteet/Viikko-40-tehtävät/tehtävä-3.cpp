#include <iostream>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

/* Tekijä: Riyadh Muradi */

/* 3. Kirjoita ohjelma, joka kysyy käyttäjältä positiivisen kokonaisluvun (vähintään 1) ja tulostaa for-silmukkaa eli
lukumääräistä toistoa käyttäen luvun 0 ja sen jälkeen vuoron perään luvut 1, -1, 2, -2 jne. käyttäjän antamaan lukuun asti.

Esimerkiksi jos käyttäjä antaa luvun 5, ohjelman tulostus on seuraava:
Luvut ovat: 0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5. */

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    int luvut;

    cout << "Kirjoita positiivinen kokonaisluku (vähintään 1): ";
    cin >> luvut;

    /* Tulostetaan vaadittu jono: x, -x */
    cout << "Luvut ovat: ";
    cout << 0;
    for (int i = 1; i <= luvut; ++i)
    {
        cout << ", " << i << ", " << -i;
    }
    cout << "." << endl;

    return 0;
    /* return EXIT_SUCCESS; */
}