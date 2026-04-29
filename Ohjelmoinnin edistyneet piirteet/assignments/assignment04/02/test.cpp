#include <iostream>
#include <sstream>
#include <string>

#include "Engine.h"
#include "Vehicle.h"

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

    Engine e1(250, "Diesel");
    Vehicle v1("Volvo", "XC90", 2024, e1);

    // Vehicle constructor values
    check("Vehicle constructor values",
          v1.getBrand() == "Volvo" && v1.getModel() == "XC90" &&
              v1.getYear() == 2024 && v1.getEngine().getHorsepower() == 250 &&
              v1.getEngine().getFuelType() == "Diesel");

    // Vehicle toString format
    check("Vehicle toString format",
          v1.toString() == "Vehicle(Volvo, XC90, 2024, Engine(250, Diesel))");

    // Engine toString format
    check("Engine toString format",
          e1.toString() == "Engine(250, Diesel)");

    // operator<< matches toString
    ostringstream oss;
    oss << v1;
    check("operator<< matches toString", oss.str() == v1.toString());

    // operator== same vehicles
    Engine e2(250, "Diesel");
    Vehicle v2("Volvo", "XC90", 2024, e2);
    check("operator== same vehicles", v1 == v2);

    // operator== different vehicles
    Engine e3(150, "Petrol");
    Vehicle v3("Toyota", "Corolla", 2023, e3);
    check("operator== different vehicles", !(v1 == v3));

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
