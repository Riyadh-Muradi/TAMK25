#include <iostream>

using namespace std;

enum KolmioTyyppi
{
    EPASAAANNOTON,
    TASAKYLKINEN,
    TASASIVUINEN,
    SUORAKULMAINEN
};

bool onKolmiollinen(double s1, double s2, double s3, KolmioTyyppi &tyyppi)
{

    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
    {
        return false;
    }

    if (s1 == s2 && s2 == s3)
    {
        tyyppi = TASASIVUINEN;
    }
    else if (s1 * s1 + s2 * s2 == s3 * s3 || s1 * s1 + s3 * s3 == s2 * s2 || s2 * s2 + s3 * s3 == s1 * s1)
    {
        tyyppi = SUORAKULMAINEN;
    }
    else if (s1 == s2 || s1 == s3 || s2 == s3)
    {
        tyyppi = TASAKYLKINEN;
    }
    else
    {
        tyyppi = EPASAAANNOTON;
    }

    return true;
}

int main()
{
    double a, b, c;
    KolmioTyyppi tulos;

    cout << "Anna 1. sivu: ";
    cin >> a;
    cout << "Anna 2. sivu: ";
    cin >> b;
    cout << "Anna 3. sivu: ";
    cin >> c;

    if (onKolmiollinen(a, b, c, tulos))
    {
        cout << "Onnistuu tyyppi: ";
        if (tulos == TASASIVUINEN)
        {
            cout << "tasasivuinen";
        }
        if (tulos == SUORAKULMAINEN)
        {
            cout << "suorakulmainen";
        }
        if (tulos == TASAKYLKINEN)
        {
            cout << "tasakylkinen";
        }
        if (tulos == EPASAAANNOTON)
        {
            cout << "epasäännöllinen";
        }
        cout << endl;
    }
    else
    {
        cout << "Ei voida muodostaa kolmioota" << endl;
    }

    return 0;
}