#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream tiedosto;
    tiedosto.open("rand.txt");

    if (!tiedosto)
    {
        cout << "virhe avamisessa" << endl;
        return 1;
    }

    double luku;
    double summa = 0;
    int maara = 0;

    while (tiedosto >> luku)
    {
        summa += luku;
        maara++;
    }

    if (maara > 0)
    {
        cout << "lukuja: " << maara << endl;
        cout << "lukujen summa: " << summa << endl;
        cout << "lukujen keskiarvo: " << summa / maara << endl;
    }
    else
    {
        cout << "tiedosto oli tyhjä" << endl;
    }

    tiedosto.close();
    return 0;
}