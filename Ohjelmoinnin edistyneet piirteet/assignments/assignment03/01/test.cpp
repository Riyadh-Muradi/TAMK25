#include <iostream>
#include <string>

#include "Person.h"
#include "Student.h"

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

    Person person("Alice", 30);
    check("Person toString", person.toString() == "Person(Alice, 30)");

    Student student("Bob", 20, "S123");
    check("Student toString",
          student.toString() == "Student(Bob, 20, S123)");
    check("Student getters", student.getName() == "Bob" && student.getAge() == 20 &&
                                  student.getStudentId() == "S123");

    student.setAge(21);
    student.setStudentId("S456");
    check("Student setters", student.getAge() == 21 &&
                                student.getStudentId() == "S456");

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
