#include <iostream>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

/* Tekijä: Riyadh Muradi */

/* */

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    int luku = 1;

    cout << "Anna lukum, jolle kertoma lasketaan: ";
    cin >> luku;

    for (int i = 1; i <= luku; i++)
    {
        if (i % 2 == 0)
            cout << i << "";
    }

    return 0;
    /* return EXIT_SUCCESS; */
}