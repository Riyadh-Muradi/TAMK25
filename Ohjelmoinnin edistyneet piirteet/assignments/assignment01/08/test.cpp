#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "BankAccount.h"

static_assert(std::is_default_constructible<BankAccount>::value,
              "BankAccount must be default constructible");
static_assert(std::is_constructible<BankAccount, std::string, int, double>::value,
              "BankAccount must be constructible from (string, int, double)");

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

    BankAccount a;
    check("default constructor values", a.getOwner().empty() && a.getId() == 0 && a.getBalance() == 0.0);
    check("toString for empty owner", a.toString() == "BankAccount(\"\", 0, 0.000000)");

    BankAccount b("Alice", 42, 100.0);
    check("parameterized constructor values",
          b.getOwner() == "Alice" && b.getId() == 42 && b.getBalance() == 100.0);

    check("deposit rejects non-positive", !b.deposit(0.0));
    check("deposit increases balance", b.deposit(50.0) && b.getBalance() == 150.0);

    check("withdraw rejects overdraw", !b.withdraw(1000.0));
    check("withdraw decreases balance", b.withdraw(30.0) && b.getBalance() == 120.0);

    BankAccount d("Bob", 7, 25.0);
    check("operator== compares id", !(b == d));

    BankAccount combined = b + d;
    check("operator+ combines balances", combined.getBalance() == 145.0);
    check("operator+ owner and id", combined.getOwner() == "combined" && combined.getId() == 0);

    std::ostringstream oss;
    oss << b;
    check("operator<< matches toString", oss.str() == b.toString());

    bool threw = false;
    try {
        b.setId(-1);
    } catch (...) {
        threw = true;
    }
    check("setId throws on negative", threw);

    threw = false;
    try {
        b.setBalance(-1.0);
    } catch (...) {
        threw = true;
    }
    check("setBalance throws on negative", threw);

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
