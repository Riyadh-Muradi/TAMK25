#include <iostream>

using namespace std;

int Tehtava_1()
{
    cout << "Ollako vai eiko olla." << endl;
    cout << "Kas siina pulma.";

    return 0;
}

int Tehtava_1()
{
    int number;

    cout << "Syota luku: ";

    cin >> number;

    cout << "Syötit luvun " << number << endl;

    return 0;
}

int Tehtava_1()
{
    int age;

    cout << "Anna ikäsi? ";
    
    cin >> age;

    cout << "50 vuoden kuluttua oot " << age + 50 << " vuotias" << endl;

    return 0;
}

int Tehtava_1()
{
    int luku1, luku2;

    cout << "Syötä ensimmäinen luku: ";
    cin >> luku1;

    cout << "Syötä toinen luku: ";
    cin >> luku2;

    cout << "Lukujen erotus on " << luku1 - luku2 << endl;
    cout << "Lukujen tulo on " << luku1 * luku2 << endl;

    return 0;
}
