#include <iostream>
#include <string>

using namespace std;

/* Tekijä: Riyadh Muradi */
/* Hotellivarausohjelma - Lopputyö */

const int HUONEIDEN_MAARA = 50;
const int HINTA_PER_YO = 100;

struct Huone
{
    int numero;
    bool varattu;
    string asiakasNimi;
};

Huone huoneet[HUONEIDEN_MAARA];

/* Hotellin alustus */

void alustaHotelli()
{
    for (int i = 0; i < HUONEIDEN_MAARA; i++)
    {
        huoneet[i].numero = i + 1;
        huoneet[i].varattu = false;
        huoneet[i].asiakasNimi = "";
    }
}

/* Pääohjelma */

int main()
{
    alustaHotelli();

    string nimi;
    int huoneNumero;
    int yot;

    cout << "Anna nimesi: ";
    getline(cin, nimi);

    cout << "Valitse huone (1-" << HUONEIDEN_MAARA << "): ";
    cin >> huoneNumero;

    /* Tarkistetaan onko huone varattu */
    if (huoneet[huoneNumero - 1].varattu)
    {
        cout << "Huone on jo varattu!" << endl;
        return 0;
    }

    cout << "Montako yötä: ";
    cin >> yot;

    /* Tehdään varaus */
    huoneet[huoneNumero - 1].varattu = true;
    huoneet[huoneNumero - 1].asiakasNimi = nimi;

    /* Lasketaan hinta */
    int kokonaishinta = yot * HINTA_PER_YO;

    cout << "\nVaraus vahvistettu!" << endl;
    cout << "Asiakas: " << nimi << endl;
    cout << "Huone: " << huoneNumero << endl;
    cout << "Yöt: " << yot << endl;
    cout << "Hinta: " << kokonaishinta << " euroa" << endl;

    return 0;
}
