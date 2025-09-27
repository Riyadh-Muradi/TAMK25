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

    cout << "Anna kokonaisluku: ";
    cin >> luku;

    cout << "Parilliset luvut: ";

    for (int i = 0; i <= luku; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
    /* return EXIT_SUCCESS; */
}
