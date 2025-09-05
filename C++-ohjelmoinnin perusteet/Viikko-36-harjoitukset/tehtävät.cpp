#include <iostream>

using namespace std;

/*
1. Tee ohjelma, joka tulostaa näytölle seuraavan tekstin:

Ollako vai eiko olla.

Kas siina pulma.
*/

int Tehtava_1()
{
    cout << "Ollako vai eiko olla." << endl;
    cout << "Kas siina pulma.";
    
    return 0;
}

/*
2. Tee ohjelma, joka kysyy käyttäjältä kokonaisluvun, jonka jälkeen ohjelma kertoo, minkä luvun käyttäjä syötti.

Esimerkki:
Syota luku: 30
Syötit luvun 30
*/
int Tehtava_1()
{
    int number;

    cout << "Syota luku: ";
    cin >> number;

    cout << "Syötit luvun " << number << endl;

    return 0;
}

/*
3. Tee ohjelma, joka kysyy käyttäjältä iän ja kertoo tämän jälkeen käyttäjälle hänen ikänsä 50 vuoden kuluttua.

Esim:
Anna ikäsi? 23
50 vuoden kuluttua olet 73 vuotias
*/
int Tehtava_1()
{
    int age;

    cout << "Anna ikäsi? ";
    cin >> age;

    cout << "50 vuoden kuluttua oot " << age + 50 << " vuotias" << endl;

    return 0;
}

/*
4. Tee ohjelma, joka kysyy käyttäjältä kaksi lukua ja tulostaa niiden erotuksen ja tulon.

Esimerkki:
Syota 1. luku: 5
Syota 2. luku: 3
Lukujen erotus on 2
Lukujen tulo on 15
*/
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
