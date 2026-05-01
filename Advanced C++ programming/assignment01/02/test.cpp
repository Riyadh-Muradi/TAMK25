#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "Point.h"

namespace fs = std::filesystem;

static bool file_exists_nonempty(const fs::path& path) {
    std::error_code ec;
    if (!fs::exists(path, ec) || !fs::is_regular_file(path, ec)) {
        return false;
    }
    auto size = fs::file_size(path, ec);
    return !ec && size > 0;
}

static bool point_has_public_fields() {
    Point p;
    p.x = 10;
    p.y = 20;
    return p.x == 10 && p.y == 20;
}

int main() {
    const fs::path base = fs::path(__FILE__).parent_path();

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

    check("Point.cpp exists and is non-empty",
          file_exists_nonempty(base / "Point.cpp"));
    check("01.txt exists and is non-empty",
          file_exists_nonempty(base / "01.txt"));
    check("02.txt exists and is non-empty",
          file_exists_nonempty(base / "02.txt"));
    check("03.txt exists and is non-empty",
          file_exists_nonempty(base / "03.txt"));
    check("04.txt exists and is non-empty",
          file_exists_nonempty(base / "04.txt"));
    check("05.txt exists and is non-empty",
          file_exists_nonempty(base / "05.txt"));
    check("Point exposes public x/y fields", point_has_public_fields());

    if (failures == 0) {
        std::cout << "RESULT: PASS (" << tests << " tests)\n";
        return 0;
    }

    std::cout << "RESULT: FAIL (" << failures << " failed of " << tests << ")\n";
    return 1;
}
