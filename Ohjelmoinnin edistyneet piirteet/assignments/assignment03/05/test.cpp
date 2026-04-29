#include <iostream>
#include <string>
#include <type_traits>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

static_assert(is_abstract_v<Person>, "Person must be abstract");
static_assert(!is_abstract_v<Student>, "Student must not be abstract");
static_assert(!is_abstract_v<Teacher>, "Teacher must not be abstract");

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

    check("Person is abstract", is_abstract_v<Person>);

    Student student("Bob", "S123");
    check("Student drink", student.drink() == "Drinking energy drink");

    Teacher teacher("Charlie", "C++");
    check("Teacher drink", teacher.drink() == "Drinking tea");

    Person* p1 = &student;
    Person* p2 = &teacher;
    check("Polymorphic student drink",
          p1->drink() == "Drinking energy drink");
    check("Polymorphic teacher drink", p2->drink() == "Drinking tea");

    check("Student excuse",
          student.excuseForBeingLate() == "My alarm didn't go off");
    check("Teacher excuse",
          teacher.excuseForBeingLate() == "I was looking for the classroom");

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests
              << ")\n";
    return 1;
}
