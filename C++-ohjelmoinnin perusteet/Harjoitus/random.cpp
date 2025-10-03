#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Tekijä: Riyadh Muradi */

/* */

int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8");

    srand(time(0));

    int randNum = 50 + rand() % 51;

    return 0;
    /* return EXIT_SUCCESS; */
}