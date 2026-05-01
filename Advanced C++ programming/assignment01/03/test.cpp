#include <iostream>
#include <string>
#include <type_traits>

#include "Point.h"

static_assert(std::is_same<decltype(&Point::getX), int (Point::*)()>::value,
              "getX must be non-const and return int");
static_assert(std::is_same<decltype(&Point::getY), int (Point::*)()>::value,
              "getY must be non-const and return int");
static_assert(std::is_same<decltype(&Point::setX), bool (Point::*)(int)>::value,
              "setX must return bool");
static_assert(std::is_same<decltype(&Point::setY), void (Point::*)(int)>::value,
              "setY must return void");

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

    Point p;

    check("setX rejects negative values", !p.setX(-1));
    check("setX accepts valid values", p.setX(5));
    check("getX returns assigned value", p.getX() == 5);

    bool threw = false;
    try {
        p.setY(-1);
    } catch (...) {
        threw = true;
    }
    check("setY throws on negative values", threw);

    p.setY(8);
    check("getY returns assigned value", p.getY() == 8);

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
