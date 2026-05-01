#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "Point.h"

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

    Point a(1, 2);
    Point b(3, 4);

    check("toString format", a.toString() == "Point(1, 2)");

    std::ostringstream oss;
    oss << a;
    check("operator<< matches toString", oss.str() == a.toString());

    check("operator== false for different points", !(a == b));

    Point c = a + b;
    check("operator+ sums coordinates", c.getX() == 4 && c.getY() == 6);

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
