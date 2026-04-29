#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "Battery.h"
#include "Phone.h"

int main() {
    int tests = 0;
    int failures = 0;

    auto check = [&](const std::string& name, bool ok) {
        ++tests;
        if (ok) {
            std::cout << "PASS: " << name << "\n";
        } else {
            std::cout << "FAIL: " << name << "\n";
            ++failures;
        }
    };

    static_assert(std::is_copy_constructible<Phone>::value,
                  "Phone must be copy constructible");
    static_assert(std::is_copy_assignable<Phone>::value,
                  "Phone must be copy assignable");

    Battery battery(3000);
    check("Battery toString", battery.toString() == "Battery(3000 mAh)");

    Phone a("Nokia", 3000);
    check("Phone toString", a.toString() == "Phone(Nokia, Battery(3000 mAh))");

    Phone b = a;
    check("Copy constructor copies data",
          b.getModel() == "Nokia" && b.getBatteryCapacity() == 3000);

    Phone c("Samsung", 5000);
    c = a;
    check("Copy assignment copies data",
          c.getModel() == "Nokia" && c.getBatteryCapacity() == 3000);

    a.setBatteryCapacity(3500);
    check("Deep copy keeps copies unchanged",
          b.getBatteryCapacity() == 3000 && c.getBatteryCapacity() == 3000);

    std::ostringstream oss;
    oss << a;
    check("operator<< matches toString", oss.str() == a.toString());

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
