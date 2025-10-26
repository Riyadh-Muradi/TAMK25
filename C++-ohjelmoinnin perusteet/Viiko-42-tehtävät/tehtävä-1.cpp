#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */

/*

🧩 Tehtävä 4: Lajittelu (Bubble Sort)
Taso: keskivaikea

Kirjoita ohjelma, joka:

Tallentaa taulukkoon 10 kokonaislukua (kovakoodattu tai syötetty).

Tulostaa ne ennen ja jälkeen järjestämisen.

Lajittelee luvut nousevaan järjestykseen käyttäen vaihtolajittelua (bubble sort).

💡 Vihje: käytä kaksoissilmukkaa (sisäkkäiset for -lauseet) ja väliaikaismuuttujaa temp.

*/

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    const int LUKUJEN_MAARA = 10;
    int luvut[LUKUJEN_MAARA];

    cout << "Kirjoita " << LUKUJEN_MAARA << " kokonaisluka: ";

    for (int i = 0; i < LUKUJEN_MAARA; i++)
    {
        cin >> luvut[i];
    }

    for (int i = 0; i < luvut - 1; i++)
    {

        for (int j = 0; j < luvut - i - 1; j++)
        {

            if (luvut[j] > luvut[j + 1])
                swap(luvut[j], luvut[j + 1]);
        }
    }

    return 0;
    /* return EXIT_SUCCESS; */
}