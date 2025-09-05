#include <iostream>
using namespace std;

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
