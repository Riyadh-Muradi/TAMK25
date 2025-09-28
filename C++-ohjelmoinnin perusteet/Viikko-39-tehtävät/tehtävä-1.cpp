#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* 1. Tee ohjelma, kysyy käyttäjältä positiivista kokonaislukua ja tulostaa tekstin ”Luvut ovat: ” ja sen perään luvut annetusta luvusta sen vastalukuun. Käytä loppuehtoista silmukkaa. Esimerkiksi jos käyttäjä antaa luvun 5, ohjelma antaa seuraavanlaisen tulostuksen:
Luvut ovat:  5  4  3  2  1  0  -1  -2  -3  -4  -5  */

int main()
{
    setlocale(LC_ALL, "FI_fi");

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

    return 0;
    /* return EXIT_SUCCESS; */
}
