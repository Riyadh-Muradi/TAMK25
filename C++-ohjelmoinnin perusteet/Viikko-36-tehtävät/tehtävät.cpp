#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

/* Tekijä: Riyadh Muradi */

void assignment1()
{
    /* Tehtävä 1 */
    cout << "Hello World!" << endl;
}

void assignment2()
{
    /* Tehtävä 2 */
    cout << "Ollako vai eiko olla." << endl;
    cout << "Kas siina pulma." << endl;
}

void assignment3()
{
    /* Tehtävä 3 */
    int number;

    cout << "Syota luku: ";
    cin >> number;

    cout << "Syötit luvun " << number << endl;
}

void assignment4()
{
    /* Tehtävä 4 */
    int age;

    cout << "Anna ikäsi? ";
    cin >> age;

    cout << "50 vuoden kuluttua oot " << age + 50 << " vuotias" << endl;
}

void assignment5()
{
    /* Tehtävä 5 */
    int luku1, luku2;

    cout << "Syötä ensimmäinen luku: ";
    cin >> luku1;

    cout << "Syötä toinen luku: ";
    cin >> luku2;

    cout << "Lukujen erotus on " << luku1 - luku2 << endl;
    cout << "Lukujen tulo on " << luku1 * luku2 << endl;
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
        cout << " 4) Tehtävä 4\n";
        cout << " 5) Tehtävä 5\n";
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
        case 5:
            assignment5();
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
