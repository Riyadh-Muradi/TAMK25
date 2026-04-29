#include <iostream>
#include <sstream>
#include <string>

#include "Car.h"
#include "Heart.h"
#include "Human.h"

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

    Heart heart(60);
    check("Heart toString", heart.toString() == "Heart(60 bpm)");

    Car volvo("Volvo", "240");
    check("Car toString", volvo.toString() == "Car(Volvo, 240)");

    Human timo("Timo", 60);
    check("Human toString without car",
          timo.toString() == "Human(Timo, Heart(60 bpm), no car)");

    timo.setCar(&volvo);
    check("Human toString with car",
          timo.toString() == "Human(Timo, Heart(60 bpm), Car(Volvo, 240))");

    std::ostringstream oss;
    oss << timo;
    check("operator<< matches toString", oss.str() == timo.toString());

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
