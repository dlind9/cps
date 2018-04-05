#include "../headers/models.h"
#include "../headers/models.h"

#include "../headers/circle.h"

#include "catch.hpp"
#include <fstream>
#include <iostream>

TEST_CASE("transformations") {
    auto circle = Circle(1);
    auto correctScale = "1.000000 1.000000 scale\n";
    auto correctTranslate = "1.000000 1.000000 translate\n";

    SECTION("test scale") {
        circle.scale(1., 1.);

        REQUIRE(circle.getTransform() == correctScale);
    }

    SECTION("test translate") {
        circle.translate(1., 1.);

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

    SECTION("transformation adds to overall postscript output") {
        auto before = circle.postscript();

        circle
            .translate(1, 2)
            .rotate(2);

        auto after = circle.postscript();

        REQUIRE(before.length() < after.length());

        std::ofstream of("test-circle.ps");
        of << before << std::endl;
    }
}

