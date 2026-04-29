#include <iostream>
#include <sstream>
#include <string>

#include "Car.h"
#include "Driver.h"
#include "Engine.h"
#include "Fleet.h"
#include "Truck.h"

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

    // Driver toString
    Driver driver("Timo", 2015);
    check("Driver toString",
          driver.toString() == "Driver(Timo, 2015)");

    // Fleet addVehicle
    Fleet fleet(3);
    fleet.setDriver(&driver);
    bool added1 =
        fleet.addVehicle(new Car("Volvo", "XC90", 2024, Engine(250, "Diesel"), 5));
    bool added2 =
        fleet.addVehicle(new Truck("Scania", "R500", 2023, Engine(500, "Diesel"), 25));
    check("Fleet addVehicle",
          added1 && added2 && fleet.getCount() == 2);

    // Fleet toString with driver
    string expected =
        "Fleet(Driver(Timo, 2015), 2 vehicles)\n"
        "- Car(Volvo, XC90, 2024, Engine(250, Diesel), 5)\n"
        "- Truck(Scania, R500, 2023, Engine(500, Diesel), 25)";
    check("Fleet toString with driver", fleet.toString() == expected);

    // Fleet toString without driver
    {
        Fleet empty(2);
        check("Fleet toString without driver",
              empty.toString() == "Fleet(no driver, 0 vehicles)");
    }

    // Fleet full returns false
    Fleet small(1);
    small.addVehicle(new Car("BMW", "320", 2024, Engine(180, "Petrol"), 5));
    Truck* rejected = new Truck("MAN", "TGX", 2023, Engine(450, "Diesel"), 30);
    bool addedWhenFull = small.addVehicle(rejected);
    if (!addedWhenFull) {
        delete rejected;
    }
    check("Fleet full returns false", !addedWhenFull && small.getCount() == 1);

    // Copy constructor copies data
    Fleet copy(fleet);
    check("Copy constructor copies data",
          copy.toString() == fleet.toString() && copy.getCount() == 2);

    // Copy assignment copies data
    Fleet assigned(1);
    assigned = fleet;
    check("Copy assignment copies data",
          assigned.toString() == fleet.toString() && assigned.getCount() == 2);

    // Deep copy keeps copies unchanged
    fleet.addVehicle(new Car("Audi", "A4", 2024, Engine(200, "Petrol"), 5));
    check("Deep copy keeps copies unchanged",
          fleet.getCount() == 3 && copy.getCount() == 2 &&
              assigned.getCount() == 2);

    // Destructor frees memory
    {
        Fleet* heapFleet = new Fleet(2);
        heapFleet->addVehicle(
            new Car("Tesla", "3", 2024, Engine(0, "Electric"), 5));
        heapFleet->addVehicle(
            new Truck("Iveco", "Daily", 2023, Engine(150, "Diesel"), 10));
        delete heapFleet;
    }
    check("Destructor frees memory", true);

    // operator<< matches toString
    ostringstream oss;
    oss << copy;
    check("operator<< matches toString", oss.str() == copy.toString());

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
