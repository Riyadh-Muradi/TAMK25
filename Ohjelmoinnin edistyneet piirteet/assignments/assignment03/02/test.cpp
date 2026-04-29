#include <fstream>
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

    Person person;
    check("Person getter age", person.getAge() == 1);
    check("Person getter id", person.getId() == 2);
    check("Person getter name", person.getName() == "Alice");

    Student student;
    check("Student sums age+id", student.sumAccessible() == 3);

    check("Student getter name", student.getName() == "Alice");

    student.age = 10;
    check("Student uses updated age", student.sumAccessible() == 12);

    {
        ifstream f("02/02.txt");
        check("02.txt exists", f.good() && f.peek() != ifstream::traits_type::eof());
    }

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests
              << ")\n";
    return 1;
}
