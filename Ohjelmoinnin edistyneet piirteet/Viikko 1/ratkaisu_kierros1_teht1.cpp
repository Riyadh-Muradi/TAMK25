#include <iostream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    /* A */
    int x = 67;
    int *y = &x;

    cout << "x arvo: " << x << endl;
    cout << "y tallennettu: " << y << endl;
    cout << "nykyinen arvon osoitus: " << *y << endl;

    /* B */
    *y = 7;

    cout << "x uus arvo: " << x << endl;

    /* C
    x osoite ja y sisältö ovat samat, joten y osoittaa x muuttujaa
    */
    cout << "x sisalto: " << x << endl;
    cout << "x osoite: " << &x << endl;
    cout << "y sisalto: " << y << endl;
    cout << "y oma osoite: " << &y << endl;

    /* D */
    cout << "x: " << x << endl;
    cout << "tulos: " << *(&x) << endl;

    /* E */
    cout << "x: " << sizeof(x) << " tavua\n";
    cout << "y: " << sizeof(y) << " tavua\n";

    /* F
    Debug ei toimi.
    */

    /* G */
    int *z;

    cout << "z: " << z << endl;

    /* H */
    /* cout << *z << endl; */
    /* Osoitin sisältää roskaa niin antaa virheellistä tietoa. */

    /* I */
    z = nullptr;

    cout << "z nullptr: " << z << endl;
    /* cout << "z: " << *z << endl; */

    return 0;
}