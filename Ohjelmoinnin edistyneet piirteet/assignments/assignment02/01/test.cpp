#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "Line.h"
#include "Point.h"

static bool nearly_equal(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) <= eps;
}

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

    Point a(0, 0);
    Point b(3, 4);
    Line line(a, b);

    check("Point toString format", a.toString() == "Point(0, 0)");
    check("Line toString format",
          line.toString() == "Line(Point(0, 0), Point(3, 4))");
    check("Line length", nearly_equal(line.length(), 5.0));

    line.moveBy(1, 2);
    check("Line moveBy updates start",
          line.getStart().getX() == 1 && line.getStart().getY() == 2);
    check("Line moveBy updates end",
          line.getEnd().getX() == 4 && line.getEnd().getY() == 6);

    std::ostringstream oss;
    oss << line;
    check("operator<< matches toString", oss.str() == line.toString());

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
