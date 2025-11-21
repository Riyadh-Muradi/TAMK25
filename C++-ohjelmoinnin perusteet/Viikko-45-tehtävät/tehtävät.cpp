#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

/* Tekijä: Riyadh Muradi */

const int ARVONTOJEN_MAARA = 1000;
const char HISTOGRAMMI_MERKKI = '*';

void tarkistaTeini(int ika)
{
    bool teini;

    /* Tarkistetaan onko ikä 13-19 välillä */
    if (ika >= 13 && ika <= 19)
    {
        teini = true;
    }
    else
    {
        teini = false;
    }

    if (teini)
    {
        cout << "Oot teini-ikäinen (true)\n";
    }
    else
    {
        cout << "Et ole teini-ikäinen (false)\n";
    }
}

void assignment1()
{
    /* Tehtävä 1 */
    int ika;
    cout << "Kirjoita ikä: ";
    cin >> ika;

    tarkistaTeini(ika);
}

void tulostaFibonacci(int n)
{
    int a = 0;
    int b = 1;
    int seuraava;

    /* Lasketaan ja tulostetaan Fibonacci-luvut */
    for (int i = 1; i <= n; i++)
    {
        cout << b << " ";
        seuraava = a + b;
        a = b;
        b = seuraava;
    }
    cout << endl;
}

void assignment2()
{
    /* Tehtävä 2 */
    int n;
    cout << "Montako Fibonacci lukua tulostetaan: ";
    cin >> n;

    tulostaFibonacci(n);
}

void arvoLuvut(int maara[])
{
    /* Nollataan laskurit */
    for (int i = 0; i < 4; i++)
        maara[i] = 0;

    /* Arvotaan luvut 1-4 ja lasketaan niiden määrät */
    for (int i = 0; i < ARVONTOJEN_MAARA; i++)
    {
        int luku = rand() % 4 + 1;
        maara[luku - 1]++;
    }
}

void assignment3()
{
    /* Tehtävä 3 */
    srand(time(0));
    int maara[4];

    /* Ajanhetki ennen arvontaa */
    auto start = high_resolution_clock::now();

    arvoLuvut(maara);

    /* Ajanhetki ohjelmanosan suorittamisen jälkeen */
    auto stop = high_resolution_clock::now();

    /* Em. ajanhetkien välinen erotus lasketaan */
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Arvottiin " << ARVONTOJEN_MAARA << " lukua:\n\n";

    /* Tulostetaan jokaisen luvun määrä ja prosenttiosuus */
    for (int i = 0; i < 4; i++)
    {
        double pros = (maara[i] / (ARVONTOJEN_MAARA * 1.0)) * 100.0;
        int pyoristetty = round(pros * 10) / 10.0;
        cout << (i + 1) << ": " << maara[i] << " kpl (" << pyoristetty << "%)\n";
    }

    /* Tulostetaan suoritusaika */
    cout << "\nAikaa kului " << duration.count() / 100.0 << " sekuntia.\n";
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
