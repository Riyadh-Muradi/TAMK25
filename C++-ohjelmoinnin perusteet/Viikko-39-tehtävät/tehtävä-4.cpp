#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* 4. Tee tehtävän nro 3 mukainen ohjelma käyttäen alkuehtoista  silmukkaa. */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    /**
     * Tulostetaan parilliset luvut väliltä 2...luku alkuehtoisella silmukalla
     */
    for (int i = 2; i <= luku; i++)
    {
        if (i % 2 == 0)
            cout << i << " ";
    }

    cout << endl;
    return 0;
    /* return EXIT_SUCCESS; */
}
