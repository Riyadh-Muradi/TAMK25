#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <climits>

using namespace std;

/* Tekijä: Riyadh Muradi */

void assignment1()
{
    /* Tehtävä 1 */
    time_t start = time(0);

    /* Lasketaan INT_MAX:iin ja tulostetaan jokaisen miljoonan kohdalla */
    int miljoonaCounter = 0;
    for (long long i = 1; i <= INT_MAX; i++)
    {
        if (i % 1000000 == 0)
        {
            miljoonaCounter++;
            cout << miljoonaCounter << ". miljoona" << endl;
        }
    }

    time_t end = time(0);
    double elapsed = difftime(end, start);

    cout << "INT_MAX saavutettu!" << endl;
    printf("Aika: %.3f sekuntia\n", elapsed);
}

void assignment2()
{
    /* Tehtävä 2 */
    const string PIN = "1234";
    int yritykset = 0;
    const int MAX_YRITYKSET = 4;
    string syote;

    cout << "Tervetuloa PIN-koodi lukitukseen!" << endl;
    cout << "Sinulla on " << MAX_YRITYKSET << " yritystä." << endl;
    cout << endl;

    while (yritykset < MAX_YRITYKSET)
    {
        cout << "Syötä PIN-koodi: ";
        getline(cin, syote);

        yritykset++;

        /* Käytetään 2,5 sekunnin viive */
        time_t start = time(0);
        while (true)
        {
            time_t end = time(0);
            double elapsed = difftime(end, start);
            if (elapsed >= 2.5)
                break;
        }

        if (syote == PIN)
        {
            cout << "Koodi oikein. Tervetuloa!" << endl;
            return;
        }
        else
        {
            cout << "Väärä koodi!" << endl;

            if (yritykset >= MAX_YRITYKSET)
            {
                break;
            }
            cout << "Yrityksiä jäljellä: " << (MAX_YRITYKSET - yritykset) << endl;
            cout << endl;
        }
    }

    system("cls");
    cout << "Virheellinen koodi liian monta kertaa. Ohjelma sulkeutuu." << endl;
}

void assignment3()
{
    /* Tehtävä 3 */
    const string NIMI = "Adam";
    int n;

    cout << "Montako yritystä?: ";
    cin >> n;

    srand(time(0));
    int netto = 0;

    for (int i = 1; i <= n; i++)
    {
        int satunnainen = rand() % 100;

        cout << i << ". yritys: ";

        if (satunnainen < 10)
        {
            cout << "2 askelta eteen" << endl;
            netto += 2;
        }
        else if (satunnainen < 50)
        {
            cout << "1 askel eteen" << endl;
            netto += 1;
        }
        else if (satunnainen < 70)
        {
            cout << NIMI << " pysyy paikallaan" << endl;
        }
        else if (satunnainen < 95)
        {
            cout << "1 askel taakse" << endl;
            netto -= 1;
        }
        else
        {
            cout << "2 askelta taakse" << endl;
            netto -= 2;
        }
    }

    /* Bonus: Lasketaan netto eteen-taakse */
    cout << endl;
    cout << "Netto: ";

    if (netto > 0)
    {
        cout << netto << " askel(ta) eteen" << endl;
    }
    else if (netto < 0)
    {
        cout << abs(netto) << " askel(ta) taakse" << endl;
    }
    else
    {
        cout << "Paikoillaan" << endl;
    }
}

const double VIERIMISKEHAN_KERROIN = 3.049;

double laskeHalkaisija(double leveys, double profiiliKorkeus, double vanneHalkaisija)
{
    /* Ulkohalkaisija = 25,4*vannekoko + 2*leveys*profiilikorkeus/100 */
    double halkaisija = 25.4 * vanneHalkaisija + 2 * leveys * profiiliKorkeus / 100.0;
    return halkaisija;
}

double laskeVierimiskeha(double leveys, double profiiliKorkeus, double vanneHalkaisija)
{
    /* Vierimiskehä = kerroin*ulkohalkaisija */
    double halkaisija = laskeHalkaisija(leveys, profiiliKorkeus, vanneHalkaisija);
    double vierimiskeha_tulos = VIERIMISKEHAN_KERROIN * halkaisija;
    return vierimiskeha_tulos;
}

void assignment4()
{
    /* Tehtävä 4 */
    double leveys;
    double profiiliKorkeus;
    double vanneHalkaisija;

    cout << "Anna renkaan leveys, millimetriä: >> ";
    cin >> leveys;

    cout << "Anna renkaan korkeusprofiili, prosenttia leveydestä: >> ";
    cin >> profiiliKorkeus;

    cout << "Anna vanteen halkaisija, tuumaa: >> ";
    cin >> vanneHalkaisija;

    double halkaisija = laskeHalkaisija(leveys, profiiliKorkeus, vanneHalkaisija);
    double vierimiskeha_tulos = laskeVierimiskeha(leveys, profiiliKorkeus, vanneHalkaisija);

    /* Muutetaan millimetrit senttimetreiksi */
    double halkaisijaSentit = halkaisija / 10.0;
    double vierimiskehaaSentit = vierimiskeha_tulos / 10.0;

    cout << endl;
    printf("Renkaan halkaisija on %.1f senttimetria.\n", halkaisijaSentit);
    printf("Renkaan vierimiskeha on %.1f senttimetria.\n", vierimiskehaaSentit);
}

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    while (true)
    {
        cout << "\nValitse tehtävä:\n";
        cout << " 0) Lopeta\n";
        cout << " 1) Ajan kuluminen\n";
        cout << " 2) Aikaviivelukko\n";
        cout << " 3) Satunnaistehtävä (Dementikko Adam)\n";
        cout << " 4) Renkaan koko\n";
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
        case 4:
            assignment4();
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
