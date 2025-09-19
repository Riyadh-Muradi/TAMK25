// Ask the user to enter two numbers // Read both numbers from user input // Calculate the sum of the two numbers // Print the result to the user

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter two numbers: ";

    int a;
    int b;

    cin >> a >> b;

    cout << "The sum is: " << a + b << endl;

    return 0;
}

int improved()
{

    cout << "Enter two numbers: ";

    int firstNumber, secondNumber;

    if (!(cin >> firstNumber >> secondNumber))
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    cin >> firstNumber >> secondNumber;

    cout << "The sum is: " << firstNumber + secondNumber << endl;

    return 0;
}