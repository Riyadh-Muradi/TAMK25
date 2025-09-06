// Ask the user to enter their name // Read the name from user input // Print a personalized greeting using their name

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Enter a radius: ";
    double radius;
    cin >> radius;

    const double pi = 3.14;
    double area = pi * pow(radius, 2);

    cout << area;

    return 0;
}
