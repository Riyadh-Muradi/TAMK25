#include <iostream>

using namespace std;

int main()
{

    int a = 1;
    int b = 2;

    /* Make it so that when printing A it should give the value of b */

    int c = a;
    a = b;
    b = c;

    cout << a;

    return 0;
}

int exercise1()
{

    double x = 10;
    double y = 5;
    double z = (x + 10) / (3 * y);

    cout << z;

    return 0;
}

int exercise2()
{
    int x = 10;
    int y = 11;

    /*
    cout << "x = ";
    cout << x;
    ^
    |
    */

    cout << "x = " << x << endl
         << "y = " << y;

    return 0;
}

int exercise3()
{

    /*
    const int sales = 95000;
    const int state_tax = 4;
    const int county_tax = 2;

    cout << "Sales: " << sales << endl
         << "State tax: " << state_tax << endl
         << "County tax: " << county_tax << endl;

    cout << "Total tax: " << state_tax + county_tax;
    */

    // correct way

    double sales = 95000;
    cout << "Sales: $" << sales << endl;

    const double state_tax_rate = .04;
    double state_tax = sales * state_tax_rate;
    cout << "State tax: $" << state_tax << endl;

    const double county_tax_rate = .02;
    double county_tax = sales * county_tax_rate;
    cout << "County tax: $" << county_tax << endl;

    double total_tax = county_tax + state_tax;
    cout << "Total tax: $" << total_tax;

    return 0;
}

int exercise4()
{
    cout << "Enter values for x and y: ";

    double x;
    double y;

    cin >> x >> y;
    cout << x + y;

    return 0;
}

int exercise5()
{
    //°C = (°F - 32) × 5/9
    cout << "Enter a °F temperature to convert to °C: ";

    int fahrenheit;
    cin >> fahrenheit;

    double celsius = (fahrenheit - 32) * 5 / 9;

    cout << "Value as °C is: " << celsius;

    return 0;
}

