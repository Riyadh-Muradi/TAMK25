#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */
/* Hotellivarausohjelma - Lopputyö */

const int MAX_HUONEITA = 300;
const int MIN_HUONEITA = 30;
const int MAX_HINTA = 100;
const int MIN_HINTA = 80;

struct Huone
{
    int numero;
    bool varattu;
    string asiakasNimi;
};

Huone huoneet[MAX_HUONEITA];
int huoneidenMaara = 0;
int hintaPerYo = 0;

/* arvotaan satunnainen luku min-max väliltä */
int arvoLuku(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void alustaHotelli()
{
    /* arvotaan huoneiden määrä ja hinta */
    huoneidenMaara = arvoLuku(MIN_HUONEITA, 70);
    hintaPerYo = arvoLuku(MIN_HINTA, MAX_HINTA);

    for (int i = 0; i < huoneidenMaara; i++)
    {
        huoneet[i].numero = i + 1;
        huoneet[i].varattu = false;
        huoneet[i].asiakasNimi = "";
    }

    cout << "Hotelli alustettu" << endl;
    cout << "Huoneita yhteensä: " << huoneidenMaara << endl;
    cout << "Hinta per yö: " << hintaPerYo << "€" << endl;
    cout << endl;
}

/* tarkistaa onko huone varattu */
bool onkoHuoneVarattu(int huoneNro)
{
    if (huoneNro < 1 || huoneNro > huoneidenMaara)
    {
        return false;
    }
    return huoneet[huoneNro - 1].varattu;
}

/* arpoo vapaan huoneen automaattisesti */
int arpoVapaanHuoneen()
{
    int yrityste = 0;
    int maxYritykset = huoneidenMaara * 2;

    while (yrityste < maxYritykset)
    {
        int satunnainenHuone = arvoLuku(1, huoneidenMaara);
        if (!onkoHuoneVarattu(satunnainenHuone))
        {
            return satunnainenHuone;
        }
        yrityste++;
    }

    /* jos arpominen ei toimi, etsitään vaan suoraan */
    for (int i = 0; i < huoneidenMaara; i++)
    {
        if (!huoneet[i].varattu)
        {
            return huoneet[i].numero;
        }
    }

    return -1;
}

int main()
{
    srand(time(0));

    alustaHotelli();

    string nimi;
    int huoneNumero;
    int yot;
    int kokonaishinta;
    bool jatka = true;

    while (jatka)
    {
        cout << "\nUusi varaus" << endl;

        cout << "Anna nimesi: ";
        getline(cin, nimi);

        if (nimi.empty())
        {
            cout << "Nimi ei saa olla tyhjä!" << endl;
            continue;
        }

        huoneNumero = arpoVapaanHuoneen();

        if (huoneNumero == -1)
        {
            cout << "Valitettavasti kaikki huoneet ovat varattuja!" << endl;
            jatka = false;
            break;
        }

        cout << "Sinulle arpoi huone numero: " << huoneNumero << endl;

        cout << "Montako yötä: ";

        if (!(cin >> yot) || yot < 1)
        {
            cout << "Virhe: Syötä kelvollinen luku (vähintään 1)!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore();

        huoneet[huoneNumero - 1].varattu = true;
        huoneet[huoneNumero - 1].asiakasNimi = nimi;

        kokonaishinta = yot * hintaPerYo;

        cout << "\nVaraus vahvistettu! " << endl;
        cout << "Asiakas: " << nimi << endl;
        cout << "Huone: " << huoneNumero << endl;
        cout << "Yöt: " << yot << endl;
        cout << "Yön hinta: " << hintaPerYo << "€" << endl;
        cout << "Kokonaishinta: " << kokonaishinta << "€" << endl;
        cout << endl;

        cout << "Haluatko tehdä uuden varauksen? (k/e): ";
        string vastaus;
        getline(cin, vastaus);

        if (vastaus != "k" && vastaus != "K")
        {
            jatka = false;
        }
    }

    cout << "\nKiitos, näkemiin!" << endl;
    return 0;
}
