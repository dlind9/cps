#include "../headers/models.h"
#include "../headers/models.h"

#include "../headers/circle.h"

#include "catch.hpp"
#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("transformations") {
    auto circle = Circle(1);

    SECTION("test scale") {
        circle.scale(1., 1.);
        auto correctScale = "1.000000 1.000000 scale\n";

        REQUIRE(circle.getTransform() == correctScale);
    }

    SECTION("test translate") {
        circle.translate(1., 1.);
        auto correctTranslate = "1.000000 1.000000 translate\n";

        REQUIRE(circle.getTransform() == correctTranslate);
    }

    SECTION("test rotation") {
        for (int i = -4; i < 5; ++i) {
            auto c = Circle(1);
            c.rotate(i);
            auto correct = std::to_string(90. * i) + " rotate\n";

            REQUIRE(c.getTransform() == correct);
        }
    }
}

