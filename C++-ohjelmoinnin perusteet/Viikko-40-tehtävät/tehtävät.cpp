#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/* Tekijä: Riyadh Muradi */

void assignment1()
{
    /* Tehtävä 1 */
    srand(time(0));

    int kymppi = rand() % 11;
    int sata = 50 + rand() % 51;

    cout << "Satunnaisluvuksi väliltä 0-10 tuli: " << kymppi << endl;
    cout << "Satunnaisluku väliltä 50-100 tuli: " << sata << endl;
}

void assignment2()
{
    /* Tehtävä 2 */
    srand(time(0));

    int x0_100 = rand() % 101;
    double valilta0_1 = x0_100 / 100.0;

    int x50_100 = 50 + rand() % 51;
    double valilta05_1 = x50_100 / 100.0;

    cout << fixed << setprecision(2);
    cout << "Satunnaisluku väliltä 0-1: " << valilta0_1 << endl;
    cout << "Satunnaisluku väliltä 0,5-1: " << valilta05_1 << endl;
}

void assignment3()
{
    /* Tehtävä 3 */
    int luvut;

    cout << "Kirjoita positiivinen kokonaisluku (vähintään 1): ";
    cin >> luvut;

    cout << "Luvut ovat: ";
    cout << 0;
    for (int i = 1; i <= luvut; ++i)
    {
        cout << ", " << i << ", " << -i;
    }
    cout << "." << endl;
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
