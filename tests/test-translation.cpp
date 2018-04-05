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

        REQUIRE(s.postscript() == correctScale);
    }

    SECTION("test translate") {
        auto t = Translation(1., 1.);
        auto correctTranslate = "1.000000 1.000000 translate\n";

        REQUIRE(t.postscript() == correctTranslate);
    }

    SECTION("test rotation") {
        for (int i = -4; i < 5; ++i) {
            auto r = Rotation(i);
            auto correct = std::to_string(90. * i) + " rotate\n";

            REQUIRE(r.postscript() == correct);
        }
    }
}

