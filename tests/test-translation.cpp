#include "../headers/models.h"
#include "../headers/models.h"

#include "../headers/circle.h"

#include "catch.hpp"
#include <fstream>
using std::ofstream;
#include <iostream>

TEST_CASE("transformations") {
    auto circle = Circle(1);
    auto correctScale = "1 1 scale\n";
    auto correctTranslate = "1 1 translate\n";

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
            auto correct = std::to_string(90 * i) + " rotate\n";

            REQUIRE(c.getTransform() == correct);
        }
    }

    SECTION("transformation adds to overall postscript output") {
        auto before = circle.postscript();

        circle.translate(200, 200);
        circle.rotate(2);
        circle.scale(10, 10);

        auto after = circle.postscript();

        REQUIRE(before.length() < after.length());

        ofstream of("ps-example/test-transforms.ps");
		if (of.is_open()) {
			of << after << std::endl;
			of.close();
		}
    }
}

