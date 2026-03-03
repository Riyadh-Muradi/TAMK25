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
static_assert(std::is_default_constructible<Point>::value,
              "Point must be default constructible");
static_assert(std::is_constructible<Point, int, int>::value,
              "Point must be constructible from (int, int)");

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

    Point p_default;
    check("default constructor sets x/y to 0",
          p_default.getX() == 0 && p_default.getY() == 0);

    Point p(1, 2);
    check("parameterized constructor sets x/y", p.getX() == 1 && p.getY() == 2);

    p.moveBy(3, 4);
    check("moveBy adds deltas to position", p.getX() == 4 && p.getY() == 6);

    bool threw = false;
    try {
        Point bad(-1, 2);
        (void)bad;
    } catch (...) {
        threw = true;
    }
    check("constructor throws on negative values", threw);

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
