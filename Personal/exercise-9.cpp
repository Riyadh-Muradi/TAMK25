// Ask the user to enter their name // Read the name from user input // Print a personalized greeting using their name

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your name: ";

    string name;

    cin >> name;

    cout << "Well hello " << name << endl;

    return 0;
}

int improved()
{
    cout << "Enter your name: ";

    string name;

    getline(cin, name);

    cout << "Well hello " << name << endl;

    return 0;
}