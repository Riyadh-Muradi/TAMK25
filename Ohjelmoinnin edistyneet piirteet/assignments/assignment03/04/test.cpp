#include <fstream>
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

    // A) Constructors and base init
    Student student("Bob", "S123");
    check("Student base constructor",
          student.getName() == "Bob" && student.getStudentId() == "S123");

    Teacher teacher("Charlie", "C++");
    check("Teacher base constructor",
          teacher.getName() == "Charlie" && teacher.getSubject() == "C++");

    // B) Override
    Person person("Alice");
    check("Person drink", person.drink() == "Drinking water");
    check("Student drink", student.drink() == "Drinking energy drink");
    check("Teacher drink", teacher.drink() == "Drinking tea");

    {
        ifstream f("04/04b.txt");
        check("04b.txt exists", f.good() && f.peek() != ifstream::traits_type::eof());
    }

    // C) Virtual with polymorphism
    Person* p1 = &student;
    Person* p2 = &teacher;
    check("Polymorphic student drink",
          p1->drink() == "Drinking energy drink");
    check("Polymorphic teacher drink", p2->drink() == "Drinking tea");

    {
        ifstream f("04/04c.txt");
        check("04c.txt exists", f.good() && f.peek() != ifstream::traits_type::eof());
    }

    if (failures == 0) {
        cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    cout << "RESULT: FAIL (" << failures << " failed of " << tests
              << ")\n";
    return 1;
}
