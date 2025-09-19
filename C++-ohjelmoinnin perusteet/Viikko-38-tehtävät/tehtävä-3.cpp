#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* Tekijä Riyadh Muradi */

/* "Riittääkö sulake?" (if--else)  (1-2 p)
Kirjoita ohjelma, joka kysyy käyttäjältä jännitteen (U) ja laitteen tehon (P) sekä pistorasian takana olevan sulakkeen koon (A). Laske tämän perusteella laitteen käyttämä virta. Lopulta ohjelma ilmoittaa, riittääkö sulake ts. voiko laitteen kytkeä pistorasiaan vai ei. Jos laitteen teho on pienempi kuin sulakkeen kapasiteetti, laitteen voi kytkeä, muuten ei.

Kaava on: P = U*I, missä

- P on laitteen kuluttama teho,
- U on sähköverkon jännite (230 V tai 400 V (volttia)) ja
- I on laitteen tarvitsema sähkövirta tai sulakkeen kapasiteetti, A (ampeeria)

*/

int main()
{
    setlocale(LC_ALL, "FI_fi");

    int U, P, A;

    cout << "Anna jännite (U): ";
    cin >> U;

    cout << "Anna laitteen teho (P): ";
    cin >> P;

    cout << "Anna sulakkeen koko (A): ";
    cin >> A;

    /**
     * Lasketaan kaavalla I = P / U
     **/
    double I = P / U;
    cout << "Laitteen käyttämä virta: " << I << " A" << endl;

    if (I <= A)
    {
        cout << "Sulake riittää. Laitteen voi kytkeä pistorasiaan.";
    }
    else
    {
        cout << "Sulake ei riitä! Laitetta ei voi kytkeä.";
    }

    return 0;
}