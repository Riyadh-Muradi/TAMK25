#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* 3. Tee ohjelma, joka kysyy käyttäjältä (positiivista) kokonaislukua n ja tulostaa tekstin ”Luvut ovat: ” ja väliltä 1 – n kaikki parilliset luvut. Käytä loppuehtoista silmukkaa. Laita silmukan sisään if-lause, jolla testaat, onko luku parillinen. Käytä tähän jakojäännös-operaatiota: luku % 2 == 0. Esimerkiksi jos käyttäjä antaa luvun 12, ohjelma antaa seuraavanlaisen tulostuksen:
Luvut ovat:  2  4  6  8  10  12 */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    /**
     * Tulostetaan parilliset luvut väliltä 2...luku loppuehtoisella silmukalla
     */
    int i = 2;
    do
    {
        if (i % 2 == 0)
            cout << i << " ";
        i++;
    } while (i <= luku);

    cout << endl;
    return 0;
    /* return EXIT_SUCCESS; */
}
