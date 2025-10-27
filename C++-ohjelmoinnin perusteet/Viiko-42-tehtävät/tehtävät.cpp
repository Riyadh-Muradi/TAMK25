#include <iostream>
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

    cout << "Syötä " << LUKUJEN_MAARA << " kokonaislukua: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
    }

    cout << "\nEnnen lajittelua: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cout << luvut[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < LUKUJEN_MAARA - 1; i++)
    {
        for (int j = 0; j < LUKUJEN_MAARA - i - 1; j++)
        {
            if (luvut[j] > luvut[j + 1])
            {
                swap(luvut[j], luvut[j + 1]);
            }
        }
    }

    cout << "Lajittelun jälkeen: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cout << luvut[i] << " ";
    }
    cout << endl;
}

void assignment2()
{
    /* Tehtävä 2 */
    const int LUKUJEN_MAARA = 8;
    int taulukko[LUKUJEN_MAARA] = {2, 14, 26, 38, 60, 72, 84, 96};

    cout << "Taulukko: ";
    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cout << taulukko[i] << " ";
    }
    cout << endl;

    cout << "Anna haettava luku (1-100): ";
    int haettava;
    cin >> haettava;

    if (haettava < 1 || haettava > 100)
    {
        cout << "Luku ei kelpaa (1-100)." << endl;
        return;
    }

    int vasen = 0,
        oikea = LUKUJEN_MAARA - 1,
        indeksi = -1,
        vertailut = 0;

    while (vasen <= oikea)
    {
        int keski = (vasen + oikea) / 2;
        vertailut++;

        if (taulukko[keski] == haettava)
        {
            indeksi = keski;
            break;
        }
        else if (taulukko[keski] < haettava)
        {
            vasen = keski + 1;
        }
        else
        {
            oikea = keski - 1;
        }
    }

    cout << "Indeksi: " << indeksi << endl;
    cout << "Vertailuja: " << vertailut << endl;
}

void assignment3()
{
    /* Tehtävä 3 */
    const int NUMEROITA = 7;
    const int MAX_NUMERO = 40;
    int pelaaja[NUMEROITA], arpa[NUMEROITA];

    cout << "Valitse " << NUMEROITA << " eri numeroa väliltä 1-" << MAX_NUMERO << ":\n";
    for (int i = 0; i < NUMEROITA; i++)
    {
        bool kelvollinen = false;
        while (!kelvollinen)
        {
            cout << "Numero " << (i + 1) << ": ";
            cin >> pelaaja[i];

            if (pelaaja[i] < 1 || pelaaja[i] > MAX_NUMERO)
            {
                cout << "Numero pitää olla väliltä 1-" << MAX_NUMERO << "!\n";
                continue;
            }

            kelvollinen = true;
            for (int j = 0; j < i; j++)
            {
                if (pelaaja[j] == pelaaja[i])
                {
                    cout << "Numero on jo valittu!\n";
                    kelvollinen = false;
                    break;
                }
            }
        }
    }

    srand(time(0));
    for (int i = 0; i < NUMEROITA; i++)
    {
        bool kelvollinen;
        do
        {
            arpa[i] = rand() % MAX_NUMERO + 1;
            kelvollinen = true;
            for (int j = 0; j < i; j++)
            {
                if (arpa[j] == arpa[i])
                {
                    kelvollinen = false;
                    break;
                }
            }
        } while (!kelvollinen);
    }

    cout << "\nPelaajan numerot: ";
    for (int i = 0; i < NUMEROITA; i++)
    {
        cout << pelaaja[i] << " ";
    }
    cout << "\nArvotut numerot: ";
    for (int i = 0; i < NUMEROITA; i++)
    {
        cout << arpa[i] << " ";
    }

    int oikein = 0;
    cout << "\nOsuneet numerot: ";
    for (int i = 0; i < NUMEROITA; i++)
    {
        for (int j = 0; j < NUMEROITA; j++)
        {
            if (pelaaja[i] == arpa[j])
            {
                cout << pelaaja[i] << " ";
                oikein++;
                break;
            }
        }
    }
    cout << "\nOikein: " << oikein << "/" << NUMEROITA << endl;
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

        int valinta;
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
        cin.ignore();
        cin.get();
    }

    return 0;
}
