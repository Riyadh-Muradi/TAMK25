#include <iostream>
#include <sstream>
#include <string>

#include "Engine.h"

using namespace std;

int main() {
    int tests = 0;
    int failures = 0;

    auto check = [&](const string& name, bool ok) {
        ++tests;
        if (ok) {
            cout << "PASS: " << name << "\n";
        } else {
            cout << "FAIL: " << name << "\n";
            ++failures;
        }
    };

    // Parameterized constructor values
    Engine e1(150, "Diesel");
    check("Parameterized constructor values",
          e1.getHorsepower() == 150 && e1.getFuelType() == "Diesel");

    // Default constructor values
    Engine e2;
    check("Default constructor values",
          e2.getHorsepower() == 0 && e2.getFuelType() == "Unknown");

    // toString format
    check("toString format",
          e1.toString() == "Engine(150, Diesel)" &&
          e2.toString() == "Engine(0, Unknown)");

    // operator<< matches toString
    ostringstream oss;
    oss << e1;
    check("operator<< matches toString", oss.str() == e1.toString());

    // Constructor throws on negative hp
    bool threw = false;
    try {
        Engine e4(-1, "Petrol");
    } catch (const exception&) {
        threw = true;
    }
    check("Constructor throws on negative hp", threw);

    // Setter throws on negative hp
    threw = false;
    try {
        Engine e5;
        e5.setHorsepower(-5);
    } catch (const exception&) {
        threw = true;
    }
    check("Setter throws on negative hp", threw);

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
