#include "../headers/models.h"
#include "../headers/models.h"

#include "catch.hpp"
#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("translations") {
    SECTION("test scale") {
        auto s = Scale(1., 1.);
        auto correctScale = "1.0 1.0 scale";
        cout << s.postscript() << endl;
        REQUIRE(s.postscript() == correctScale);
    }
}

