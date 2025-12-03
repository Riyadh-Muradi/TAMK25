#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */
/* Hotellivarausohjelma - Lopputyö */

const int MAX_HUONEITA = 300;
const int MIN_HUONEITA = 40;
const int YKSIO_HINTA = 100;
const int KAKSIO_HINTA = 150;

struct Huone
{
    int numero;
    int tyyppi;
    bool varattu;
    string asiakasNimi;
    int varausnumero;
};

Huone huoneet[MAX_HUONEITA];
int huoneidenMaara = 0;
int hintaPerYo = 0;

int arvoLuku(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void alustaHotelli()
{
    huoneidenMaara = arvoLuku(MIN_HUONEITA, 70);
    if (huoneidenMaara % 2 != 0)
        huoneidenMaara--;

    int puolikas = huoneidenMaara / 2;

    for (int i = 0; i < huoneidenMaara; i++)
    {
        huoneet[i].numero = i + 1;
        huoneet[i].varattu = false;
        huoneet[i].asiakasNimi = "";
        huoneet[i].varausnumero = 0;

        if (i < puolikas)
            huoneet[i].tyyppi = 1;
        else
            huoneet[i].tyyppi = 2;
    }

    cout << "Hotelli alustettu" << endl;
    cout << "Huoneita yhteensä: " << huoneidenMaara << " (" << puolikas << " yksio + " << puolikas << " kaksio)" << endl;
    cout << "Yksio: " << YKSIO_HINTA << "€, Kaksio: " << KAKSIO_HINTA << "€" << endl;
    cout << endl;
}

bool onkoHuoneVarattu(int huoneNro)
{
    if (huoneNro < 1 || huoneNro > huoneidenMaara)
    {
        return false;
    }
    return huoneet[huoneNro - 1].varattu;
}

int arpoVapaanHuoneen(int tyyppi)
{
    for (int i = 0; i < huoneidenMaara; i++)
    {
        if (!huoneet[i].varattu && huoneet[i].tyyppi == tyyppi)
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
    int huoneTyyppi;
    int hintaPerYo;
    int varausnumero;
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

        cout << "Huoneen tyyppi (1=yksiö, 2=kaksiö): ";
        cin >> huoneTyyppi;

        if (huoneTyyppi < 1 || huoneTyyppi > 2)
        {
            cout << "Virhe: Valitse 1 tai 2!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore();

        if (huoneTyyppi == 1)
            hintaPerYo = YKSIO_HINTA;
        else
            hintaPerYo = KAKSIO_HINTA;

        huoneNumero = arpoVapaanHuoneen(huoneTyyppi);

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

        varausnumero = arvoLuku(10000, 99999);
        huoneet[huoneNumero - 1].varausnumero = varausnumero;

        kokonaishinta = yot * hintaPerYo;

        cout << "\nVaraus vahvistettu! " << endl;
        cout << "Varausnumero: " << varausnumero << endl;
        cout << "Asiakas: " << nimi << endl;

        if (huoneTyyppi == 1)
            cout << "Huone: " << huoneNumero << " (yksio)" << endl;
        else
            cout << "Huone: " << huoneNumero << " (kaksio)" << endl;

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
