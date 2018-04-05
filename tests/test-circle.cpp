#include "../headers/circle.h"
#include "../headers/circle.h"

#include "catch.hpp"

#include <iostream>

TEST_CASE("basic circle") {
    auto basicCircle = Circle(1);

    SECTION("test boundingBox is correct size") {
        auto circleBox = basicCircle.getBoundingBox();
        auto correctBox = BoundingBox(2, 2);

        REQUIRE(circleBox == correctBox);
    }

    SECTION("basic post script output") {

        REQUIRE_NOTHROW(basicCircle.postscript());
        auto output = basicCircle.postscript();

        std::cout << output << std::endl;
    }

    SECTION("transformations work") {

    }
}
