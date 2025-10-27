#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>

using namespace std;

/* Tekijä: Riyadh Muradi */

void assignment1()
{
    /* Tehtävä 1 */

    const int LUKUJEN_MAARA = 10;
    int luvut[LUKUJEN_MAARA];

    cout << "Kirjoita " << LUKUJEN_MAARA << " kokonaislukua: ";

    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
    }

    /* Tulostetaan luvut ennen lajittelua */
    cout << "\nEnnen lajittelua: ";
    for (int i = 0; i < LUKUJEN_MAARA; ++i)
        cout << luvut[i] << " ";
    cout << "\n";

    for (int i = 0; i < LUKUJEN_MAARA - 1; ++i)
    {
        for (int j = 0; j < LUKUJEN_MAARA - i - 1; ++j)
        {
            if (luvut[j] > luvut[j + 1])
            {
                swap(luvut[j], luvut[j + 1]);
            }
        }
    }

    /* Tulostetaan luvut lajittelun jälkeen */
    cout << "Lajittelun jalkeen: ";
    for (int i = 0; i < LUKUJEN_MAARA; ++i)
        cout << luvut[i] << " ";
    cout << "\n";
}

void assignment2()
{
    /* Tehtävä 5: */

    const int LUKUJEN_MAARA = 8;
    int taulukko[LUKUJEN_MAARA] = {2, 14, 26, 38, 60, 72, 84, 96};

    /* Tulostetaan taulukko */
    cout << "Taulukko: ";
    for (int i = 0; i < LUKUJEN_MAARA; ++i)
        cout << taulukko[i] << (i + 1 < LUKUJEN_MAARA ? ", " : "\n");

    /* Pyydetään haettava luku */
    cout << "Anna haettava luku (1-100): ";

    int haettava;
    cin >> haettava;

    /* Yksinkertainen validointi */
    if (haettava < 1 || haettava > 100)
    {
        cout << "Luku ei kelpaa (1-100).\n";
        return 0;
    }

    /* Binäärihaku */
    int vasen = 0;
    int oikea = LUKUJEN_MAARA - 1;
    int indeksi = -1;
    int vertailut = 0;

    while (vasen <= oikea)
    {
        int keski = (vasen + oikea) / 2;
        ++vertailut;

        if (taulukko[keski] == haettava)
        {
            indeksi = keski;
            break;
        }

        if (taulukko[keski] < haettava)
            vasen = keski + 1;
        else
            oikea = keski - 1;
    }

    /* Tulostetaan tulokset */
    cout << "\nTulokset:\n";
    cout << "Indeksi: " << indeksi << "\n";
    cout << "Vertailuja: " << vertailut << "\n";
}

void assignment3()
{
    /* Tehtävä 3: */
    int pelaaja[7];
    int arpa[7];

    // Pelaajan numerot
    cout << "Valitse 7 eri numeroa väliltä 1-40:\n";
    for (int i = 0; i < 7; i++)
    {
        int numero;
        bool kelvollinen = false;

        while (!kelvollinen)
        {
            cout << "Numero " << (i + 1) << ": ";
            cin >> numero;

            if (numero < 1 || numero > 40)
            {
                cout << "Numero pitää olla väliltä 1-40!\n";
                continue;
            }

            // Tarkista, onko numero jo valittu
            bool loytyi = false;
            for (int j = 0; j < i; j++)
            {
                if (pelaaja[j] == numero)
                {
                    loytyi = true;
                    break;
                }
            }

            if (loytyi)
            {
                cout << "Numero on jo valittu!\n";
            }
            else
            {
                pelaaja[i] = numero;
                kelvollinen = true;
            }
        }
    }

    // Arvotaan lottonumerot
    for (int i = 0; i < 7; i++)
    {
        int numero;
        bool loytyi;

        do
        {
            numero = rand() % 40 + 1;
            loytyi = false;

            for (int j = 0; j < i; j++)
            {
                if (arpa[j] == numero)
                {
                    loytyi = true;
                    break;
                }
            }
        } while (loytyi);

        arpa[i] = numero;
    }

    // Tulostus
    cout << "\n--- TULOKSET ---\n";
    cout << "Pelaajan numerot: ";
    for (int i = 0; i < 7; i++)
    {
        cout << pelaaja[i] << " ";
    }
    cout << "\n";

    cout << "Arvotut numerot: ";
    for (int i = 0; i < 7; i++)
    {
        cout << arpa[i] << " ";
    }
    cout << "\n";

    // Vertaa numerot
    cout << "Osuneet numerot: ";
    int oikein = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (pelaaja[i] == arpa[j])
            {
                cout << pelaaja[i] << " ";
                oikein++;
                break;
            }
        }
    }
    cout << "\n";

    cout << "Oikein: " << oikein << "/7\n";
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
