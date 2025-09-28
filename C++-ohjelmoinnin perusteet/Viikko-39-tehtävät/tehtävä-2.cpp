#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* 2. Tee tehtävän nro 1 mukainen ohjelma käyttäen alkuehtoista silmukkaa. */

int main()
{
    setlocale(LC_ALL, "FI_fi");

    int luku;

    cout << "Kirjoita positiivinen kokonaisluku: ";
    cin >> luku;

    cout << "Luvut ovat: ";

    for (int i = luku; i >= -luku; i--)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
    /* return EXIT_SUCCESS; */
}
