// Ask the user to enter an integer // Read the integer from user input // Check if the integer is even or odd using the modulo operator (%) // If the number is even, print a message saying it is even // If the number is odd, print a message saying it is odd

#include <iostream>
using namespace std;

int main()
{

    cout << "Enter an integer: ";
    int number;
    cin >> number;

    if (number % 2 == 0)
    {
        cout << "The number is even." << endl;
    }
    else
    {
        cout << "The number is odd." << endl;
    }

    return 0;
}