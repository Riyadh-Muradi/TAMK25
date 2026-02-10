#include <iostream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    double luku;
    cout << "Anna luku: ";
    cin >> luku;

    int ala = (int)luku;
    int yla = ala + 1;

    cout << "Luku " << luku << " sisältyy välille [ " << ala << ", " << yla << " ]." << endl;

    return 0;
}