#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <ctype.h>

using namespace std;

/* Tekijä: Riyadh Muradi */

void assignment1()
{
    /* Tehtävä 1 */

    const double PI = 3.14;
    ifstream input("input.txt");
    ofstream output("output.txt");

    /* Tarkistetaan, avautuiko input-tiedosto */
    if (!input)
    {
        cout << "Virhe: input-tiedostoa ei voitu avata.\n";
        return;
    }

    /* Tarkistetaan, avautuiko output-tiedosto */
    if (!output)
    {
        cout << "Virhe: output-tiedostoa ei voitu avata.\n";
        input.close();
        return;
    }

    double halkaisija;

    /* Luetaan halkaisijat input-tiedostosta ja lasketaan tilavuudet */
    while (input >> halkaisija)
    {
        double sade = halkaisija / 2.0;                          /* Säde on puolet halkaisijasta */
        double tilavuus = (4.0 / 3.0) * PI * sade * sade * sade; /* V = (4/3) * π * r^3 */

        cout << "Halkaisija: " << halkaisija << " Tilavuus: " << tilavuus << "\n";
        output << "Halkaisija: " << halkaisija << " Tilavuus: " << tilavuus << "\n";
    }

    input.close();
    output.close();
    cout << "Tiedostot käsitelty onnistuneesti.\n";
}

void assignment2()
{
    /* Tehtävä 2 */

    ifstream input("input.txt");
    ofstream output("output.txt");

    /* Tarkistetaan, avautuiko input-tiedosto */
    if (!input)
    {
        cout << "Virhe: input-tiedostoa ei voitu avata.\n";
        return;
    }

    /* Tarkistetaan, avautuiko output-tiedosto */
    if (!output)
    {
        cout << "Virhe: output-tiedostoa ei voitu avata.\n";
        input.close();
        return;
    }

    char merkki;

    /* Luetaan merkit input-tiedostosta ja muutetaan isoiksi kirjaimiksi */
    while (input.get(merkki))
    {
        if (merkki >= 'a' && merkki <= 'z')
        {
            merkki = toupper(merkki);
        }

        cout << merkki;
        output << merkki;
    }

    cout << "\n";
    input.close();
    output.close();
    cout << "Tiedostot käsitelty onnistuneesti.\n";
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
