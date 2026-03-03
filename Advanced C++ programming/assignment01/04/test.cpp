#include <iostream>
#include <string>
#include <type_traits>

// This test expects Point to be defined in 04/Point.cpp and declared in 04/Point.h.
#include "Point.h"

static_assert(std::is_same<decltype(&Point::getX), int (Point::*)() const>::value,
              "getX must be const and return int");
static_assert(std::is_same<decltype(&Point::getY), int (Point::*)() const>::value,
              "getY must be const and return int");
static_assert(std::is_same<decltype(&Point::setX), void (Point::*)(int)>::value,
              "setX must be non-const and return void");
static_assert(std::is_same<decltype(&Point::setY), void (Point::*)(int)>::value,
              "setY must be non-const and return void");

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
    p.setX(10);
    p.setY(20);

    check("getX returns assigned value", p.getX() == 10);
    check("getY returns assigned value", p.getY() == 20);

    const Point cp = p;
    check("const Point exposes getters", cp.getX() == 10 && cp.getY() == 20);

    const Point* p1 = &cp;
    (void)p1;

    Point* const p2 = &p;
    p2->setX(30);
    check("Point* const can modify object", p.getX() == 30);

    const Point* const p3 = &cp;
    (void)p3;

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
