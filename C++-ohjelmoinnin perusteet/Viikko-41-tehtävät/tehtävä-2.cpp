#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */

/*
Kirjoita ohjelma, joka:

Tallentaa taulukkoon 10 lukua väliltä 1–20 (voit antaa ne itse tai lukea käyttäjältä).
Tulostaa taulukon sisällön sekä piirtää jokaiselle arvolla tähtipalkin (histogrammin).
   💡Esimerkki:
    Arvo 5: *****
    Arvo 3: ***
    Arvo 8: ********
*/

/*
^
Tosi huono esimerkki
*/

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    const int LUKUJEN_MAARA = 10;
    int luvut[LUKUJEN_MAARA];
    int maara[21] = {0};

    cout << "Kirjoita " << LUKUJEN_MAARA << " lukua väliltä 1-20: ";

    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
        if (luvut[i] >= 1 && luvut[i] <= 20)
        {
            maara[luvut[i]]++;
        }
    }

    cout << "\nHistogrammi\n";

    for (int i = 1; i <= 20; i++)
    {
        if (maara[i] > 0)
        {
            cout << i << ": ";
            for (int j = 0; j < maara[i]; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    return 0;
    /* return EXIT_SUCCESS; */
}