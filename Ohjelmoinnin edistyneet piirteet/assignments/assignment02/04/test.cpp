#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "Instrument.h"
#include "Musician.h"
#include "Name.h"
#include "Studio.h"

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

    static_assert(std::is_copy_constructible<Musician>::value,
                  "Musician must be copy constructible");
    static_assert(std::is_copy_assignable<Musician>::value,
                  "Musician must be copy assignable");

    Name name("James", "Hetfield");
    check("Name toString", name.toString() == "Name(James, Hetfield)");

    Instrument instrument("Guitar", "ESP");
    check("Instrument toString",
          instrument.toString() == "Instrument(Guitar, ESP)");
    check("Instrument getType", instrument.getType() == "Guitar");
    check("Instrument getBrand", instrument.getBrand() == "ESP");

    Studio studio("Abbey Road", "London");
    check("Studio toString", studio.toString() == "Studio(Abbey Road, London)");
    check("Studio getName", studio.getName() == "Abbey Road");
    check("Studio getCity", studio.getCity() == "London");

    Musician james("James", "Hetfield", "Guitar", "ESP");
    check("Musician toString without studio",
          james.toString() ==
              "Name(James, Hetfield), Instrument(Guitar, ESP), no studio");

    james.setStudio(&studio);
    check("Musician toString with studio",
          james.toString() ==
              "Name(James, Hetfield), Instrument(Guitar, ESP), "
              "Studio(Abbey Road, London)");

    std::ostringstream oss;
    oss << james;
    check("operator<< matches toString", oss.str() == james.toString());

    Musician copy(james);
    check("Copy constructor copies data", copy.toString() == james.toString());

    Musician lars("Lars", "Ulrich", "Drums", "Tama");
    lars = james;
    check("Copy assignment copies data", lars.toString() == james.toString());

    james.setStudio(nullptr);
    check("Deep copy: changing original studio does not affect copy",
          copy.toString() ==
              "Name(James, Hetfield), Instrument(Guitar, ESP), "
              "Studio(Abbey Road, London)");

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests
              << ")\n";
    return 1;
}
