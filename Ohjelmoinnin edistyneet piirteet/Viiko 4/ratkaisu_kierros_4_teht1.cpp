

#include <iostream>

using namespace std;

int main()
{
    const int KILO = 1024;

    long koko = 100000 * KILO;
    char *dynaaminen = new (nothrow) char[koko];

    if (dynaaminen != nullptr)
    {
        cout << "Varaus " << koko / KILO << " kt onnistui" << endl;
        delete[] dynaaminen;
    }
    else
    {
        cout << "Varaus epäonnistui" << endl;
    }

    return 0;
}