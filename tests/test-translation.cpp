#include "../headers/models.h"
#include "../headers/models.h"

#include "catch.hpp"
#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("transformations") {
    SECTION("test scale") {
        auto s = Scale(1., 1.);
        auto correctScale = "1.000000 1.000000 scale\n";
        cout << s.postscript() << endl;
        REQUIRE(s.postscript() == correctScale);
    }

    SECTION("test translate") {
        auto t = Translation(1., 1.);
        auto correctTranslate = "1.000000 1.000000 translate\n";

        REQUIRE(t.postscript() == correctTranslate);
    }
}

