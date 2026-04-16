#include <iostream>
#include <string>
#include <type_traits>

#include "Point.h"

static_assert(std::is_same<decltype(&Point::getX), int (Point::*)() const>::value,
              "getX must be const and return int");
static_assert(std::is_same<decltype(&Point::getY), int (Point::*)() const>::value,
              "getY must be const and return int");
static_assert(std::is_same<decltype(&Point::setX), void (Point::*)(int)>::value,
              "setX must return void");
static_assert(std::is_same<decltype(&Point::setY), void (Point::*)(int)>::value,
              "setY must return void");
static_assert(std::is_same<decltype(&Point::moveBy), void (Point::*)(int, int)>::value,
              "moveBy must return void");

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
    p.setX(1);
    p.setY(2);

    p.moveBy(3, 4);
    check("moveBy adds deltas to position", p.getX() == 4 && p.getY() == 6);

    bool setterThrew = false;
    try {
        p.setX(-1);
    } catch (...) {
        setterThrew = true;
    }
    check("setX throws on negative values", setterThrew);

    setterThrew = false;
    try {
        p.setY(-1);
    } catch (...) {
        setterThrew = true;
    }
    check("setY throws on negative values", setterThrew);

    p.moveBy(-1, 0);
    check("moveBy allows negative deltas if final position is valid",
          p.getX() == 3 && p.getY() == 6);

    bool threw = false;
    try {
        p.moveBy(-10, 0);
    } catch (...) {
        threw = true;
    }
    check("moveBy throws if final position would be negative", threw);

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
