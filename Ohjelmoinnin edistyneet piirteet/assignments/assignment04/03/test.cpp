#include <iostream>
#include <string>
#include <type_traits>

#include "Car.h"
#include "Engine.h"
#include "Truck.h"
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

    // Vehicle is abstract
    check("Vehicle is abstract", is_abstract<Vehicle>::value);

    // Car toString format
    Car car("Volvo", "XC90", 2024, Engine(250, "Diesel"), 5);
    check("Car toString format",
          car.toString() == "Car(Volvo, XC90, 2024, Engine(250, Diesel), 5)");

    // Car purpose
    check("Car purpose", car.purpose() == "Personal transport");

    // Car getPassengerCount
    check("Car getPassengerCount", car.getPassengerCount() == 5);

    // Truck toString format
    Truck truck("Scania", "R500", 2023, Engine(500, "Diesel"), 25);
    check("Truck toString format",
          truck.toString() ==
              "Truck(Scania, R500, 2023, Engine(500, Diesel), 25)");

    // Truck purpose
    check("Truck purpose", truck.purpose() == "Cargo transport");

    // Car clone
    Vehicle* carClone = car.clone();
    check("Car clone",
          carClone->toString() == car.toString() && carClone != &car);
    delete carClone;

    // Truck clone
    Vehicle* truckClone = truck.clone();
    check("Truck clone",
          truckClone->toString() == truck.toString() && truckClone != &truck);
    delete truckClone;

    // Polymorphic car purpose
    Vehicle* vCar = &car;
    check("Polymorphic car purpose", vCar->purpose() == "Personal transport");

    // Polymorphic truck purpose
    Vehicle* vTruck = &truck;
    check("Polymorphic truck purpose",
          vTruck->purpose() == "Cargo transport");

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
