#include <iostream>
#include <string>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

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

    Person person("Alice");
    check("Person toString and drink",
          person.toString() == "Person(Alice)" &&
              person.drink() == "Drinking water");

    Student student("Bob", "S123");
    check("Student base constructor",
          student.getName() == "Bob" && student.getStudentId() == "S123");
    check("Student toString and drink",
          student.toString() == "Student(Bob, S123)" &&
              student.drink() == "Drinking energy drink");

    Teacher teacher("Charlie", "C++");
    check("Teacher base constructor",
          teacher.getName() == "Charlie" && teacher.getSubject() == "C++");
    check("Teacher toString and drink",
          teacher.toString() == "Teacher(Charlie, C++)" &&
              teacher.drink() == "Drinking tea");

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests
              << ")\n";
    return 1;
}
