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
    const int LUKUJEN_MAARA = 10;
    int luvut[LUKUJEN_MAARA];
    int kokonaisumma = 0;

    cout << "Kirjoita " << LUKUJEN_MAARA << " kokonaislukua: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
        kokonaisumma += luvut[i];
    }

    cout << "\nLuvut ovat: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cout << luvut[i] << " ";
    }

    double keskiarvo = (double)kokonaisumma / LUKUJEN_MAARA;
    cout << "\nLukujen summa: " << kokonaisumma << endl;
    cout << "Lukujen keskiarvo: " << keskiarvo << endl;
}

void assignment2()
{
    /* Tehtävä 2 */
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
}

void assignment3()
{
    /* Tehtävä 3 */
    srand(time(0));

    const int HEITOT = 6000;
    int frequency[7] = {0};

    for (int i = 0; i < HEITOT; i++)
    {
        int luku = rand() % 6 + 1;
        frequency[luku]++;
    }

    for (int i = 1; i <= 6; i++)
    {
        cout << "Sivu " << i << ": " << frequency[i] << endl;
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
