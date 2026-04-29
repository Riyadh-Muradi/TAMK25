#include <iostream>
#include <string>
#include <type_traits>

#include "Cat.h"
#include "Dog.h"
#include "Mammal.h"

using namespace std;

static_assert(is_abstract_v<Mammal>, "Mammal must be abstract");
static_assert(!is_abstract_v<Dog>, "Dog must not be abstract");
static_assert(!is_abstract_v<Cat>, "Cat must not be abstract");

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

    check("Mammal is abstract", is_abstract_v<Mammal>);

    Dog dog("Rex");
    check("Dog makeSound", dog.makeSound() == "Woof");
    check("Dog getName", dog.getName() == "Rex");

    Cat cat("Whiskers");
    check("Cat makeSound", cat.makeSound() == "Meow");
    check("Cat getName", cat.getName() == "Whiskers");

    Mammal* p1 = &dog;
    Mammal* p2 = &cat;
    check("Polymorphic dog sound", p1->makeSound() == "Woof");
    check("Polymorphic cat sound", p2->makeSound() == "Meow");

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests
              << ")\n";
    return 1;
}
