#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

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
    int alennus;
};

Huone huoneet[MAX_HUONEITA];
int huoneidenMaara = 0;

int arvoLuku(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void tallennaJSON();

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
        huoneet[i].alennus = 0;

        if (i < puolikas)
            huoneet[i].tyyppi = 1;
        else
            huoneet[i].tyyppi = 2;
    }

    cout << "Hotelli alustettu" << endl;
    cout << "Huoneita yhteensä: " << huoneidenMaara << " (" << puolikas << " yksiö + " << puolikas << " kaksiö)" << endl;
    cout << "Yksiö: " << YKSIO_HINTA << "€, Kaksiö: " << KAKSIO_HINTA << "€" << endl;
    cout << endl;

    tallennaJSON();
}

void tallennaJSON()
{
    ofstream jsonFile("data.json");

    int vapaanaHuoneita = 0;
    int varatuita = 0;

    for (int i = 0; i < huoneidenMaara; i++)
    {
        if (!huoneet[i].varattu)
            vapaanaHuoneita++;
        else
            varatuita++;
    }

    /* TODO: Formattaa JSON sillee että se on clean */
    jsonFile << "{"
             << "\"huoneidenMaara\":" << huoneidenMaara << ","
             << "\"vapaanaHuoneita\":" << vapaanaHuoneita << ","
             << "\"varatuita\":" << varatuita << ","
             << "\"yksioHinta\":" << YKSIO_HINTA << ","
             << "\"kaksioHinta\":" << KAKSIO_HINTA << ","
             << "\"huoneet\":[";

    for (int i = 0; i < huoneidenMaara; i++)
    {
        jsonFile << "{"
                 << "\"numero\":" << huoneet[i].numero << ","
                 << "\"tyyppi\":" << huoneet[i].tyyppi << ","
                 << "\"varattu\":" << (huoneet[i].varattu ? "true" : "false") << ","
                 << "\"asiakas\":\"" << huoneet[i].asiakasNimi << "\","
                 << "\"varausNumero\":" << huoneet[i].varausnumero << ","
                 << "\"alennus\":" << huoneet[i].alennus
                 << "}";
        if (i < huoneidenMaara - 1)
            jsonFile << ",";
    }

    jsonFile << "]}";
    jsonFile.close();
}

int arpoVapaanHuoneen(int tyyppi)
{
    int vapaa = -1;
    for (int i = 0; i < huoneidenMaara; i++)
    {
        if (!huoneet[i].varattu && huoneet[i].tyyppi == tyyppi)
        {
            vapaa = huoneet[i].numero;
            break;
        }
    }
    return vapaa;
}

int tarkistaHuoneTyyppi(int tyyppi)
{
    /* Tarkistetaan huonetyyppi ja palautetaan hinta */
    int hinta = 0;
    if (tyyppi == 1)
        hinta = YKSIO_HINTA;
    else
        hinta = KAKSIO_HINTA;
    return hinta;
}

void varaaHuone(int huoneNumero, string nimi)
{
    /* Laitetaan huone varatuksi */
    huoneet[huoneNumero - 1].varattu = true;
    huoneet[huoneNumero - 1].asiakasNimi = nimi;

    int varausnumero = arvoLuku(10000, 99999);
    huoneet[huoneNumero - 1].varausnumero = varausnumero;

    int sattuma = arvoLuku(1, 3);
    int alennus = 0;

    if (sattuma == 1)
        alennus = 0;
    else if (sattuma == 2)
        alennus = 10;
    else
        alennus = 20;

    huoneet[huoneNumero - 1].alennus = alennus;

    /* päivitää JSON tiedostoo */
    tallennaJSON();
}

void naytaVahvistus(int varausnumero, string asiakas, int tyyppi, int huone, int yot, int hinta, int kokonaishinta, int alennus, int hinta_alennus)
{
    /* Näytetään varauksen vahvistus */
    cout << "\nVaraus vahvistettu " << endl;
    cout << "Varausnumero: " << varausnumero << endl;
    cout << "Asiakas: " << asiakas << endl;

    if (tyyppi == 1)
        cout << "Huone: " << huone << " (yksiö)" << endl;
    else
        cout << "Huone: " << huone << " (kaksiö)" << endl;

    cout << "Yöt: " << yot << endl;
    cout << "Yön hinta: " << hinta << "€" << endl;
    cout << "Kokonaishinta: " << kokonaishinta << "€" << endl;

    if (alennus > 0)
    {
        cout << "Alennus: " << alennus << "%" << endl;
        cout << "Hinta alennoksen jälkeen: " << hinta_alennus << "€" << endl;
    }

    cout << endl;
}

bool kysy_jatka()
{
    /* Kysytään käyttäjältä jatkaa vai ei */
    cout << "Haluatko tehdä uuden varauksen? (k/e): ";
    string vastaus;
    getline(cin, vastaus);

    if (vastaus == "k" || vastaus == "K")
        return true;
    return false;
}

void etsiVaraus()
{
    /* Etsitään olemassa olevia varauksia */
    cout << "\nEtsi varaus" << endl;
    cout << "Anna asiakkaan nimi: ";

    string hakuNimi;
    getline(cin, hakuNimi);

    if (hakuNimi.empty())
    {
        cout << "Nimi ei saa olla tyhjä!" << endl;
        return;
    }

    bool loytyi = false;

    for (int i = 0; i < huoneidenMaara; i++)
    {
        if (huoneet[i].varattu && huoneet[i].asiakasNimi == hakuNimi)
        {
            loytyi = true;

            cout << "\nVaraus löytyi:" << endl;
            cout << "Varausnumero: " << huoneet[i].varausnumero << endl;
            cout << "Asiakas: " << huoneet[i].asiakasNimi << endl;
            cout << "Huone: " << huoneet[i].numero;

            if (huoneet[i].tyyppi == 1)
                cout << " (yksiö)" << endl;
            else
                cout << " (kaksiö)" << endl;

            cout << "Alennus: " << huoneet[i].alennus << "%" << endl;
            cout << endl;
        }
    }

    if (!loytyi)
    {
        cout << "Varausta ei löytynyt nimellä: " << hakuNimi << endl;
    }
}

int main()
{
    srand(time(0));

    alustaHotelli();

    string nimi;
    /* TODO: optimoi tää silleen kaikki on yhen alla */
    int huoneNumero;
    int yot;
    int kokonaishinta;
    int huoneTyyppi;
    int hintaPerYo;
    int varausnumero;
    bool jatka = true;

    while (jatka)
    {
        int valinta = 0;
        cout << "Valitse: 1 = Uusi varaus, 2 = Etsi varaus, 3 = Lopeta: ";
        cin >> valinta;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore();

        if (valinta == 2)
        {
            etsiVaraus();
            continue;
        }

        if (valinta == 3)
        {
            jatka = false;
            break;
        }

        if (valinta != 1)
            continue;

        /* TODO: input validatio omaan funtioon */
        cout << "\nUusi varaus" << endl;

        cout << "Anna nimesi: ";
        getline(cin, nimi);

        if (nimi.empty())
        {
            cout << "Nimi ei saa olla tyhjä!" << endl;
            continue;
        }

        cout << "Huoneen tyyppi (1: yksiö, 2: kaksiö): ";
        cin >> huoneTyyppi;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Virhe: Valitse 1 tai 2!" << endl;
            continue;
        }

        if (huoneTyyppi < 1 || huoneTyyppi > 2)
        {
            cout << "Virhe: Valitse 1 tai 2!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore();

        hintaPerYo = tarkistaHuoneTyyppi(huoneTyyppi);

        huoneNumero = arpoVapaanHuoneen(huoneTyyppi);

        if (huoneNumero == -1)
        {
            cout << "Kaikki huoneet varattuja!" << endl;
            jatka = false;
            break;
        }

        cout << "Sinulle arpoi huone numero: " << huoneNumero << endl;

        cout << "Montako yötä: ";
        cin >> yot;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Vähintään 1 yö!" << endl;
            continue;
        }

        if (yot < 1)
        {
            cout << "Vähintään 1 yö!" << endl;
            continue;
        }

        cin.ignore();

        varaaHuone(huoneNumero, nimi);

        varausnumero = huoneet[huoneNumero - 1].varausnumero;
        int alennus = huoneet[huoneNumero - 1].alennus;

        /* TODO: Omaan funtioon?? */
        kokonaishinta = yot * hintaPerYo;
        int alennus_euroa = (kokonaishinta * alennus) / 100;
        int hinta_alennoksen_jalkeen = kokonaishinta - alennus_euroa;

        naytaVahvistus(varausnumero, nimi, huoneTyyppi, huoneNumero, yot, hintaPerYo, kokonaishinta, alennus, hinta_alennoksen_jalkeen);

        if (!kysy_jatka())
        {
            break;
        }
    }

    cout << "\nKiitos, näkemiin" << endl;
    return 0;
}
