#include "../headers/circle.h"
#include "../headers/circle.h"

#include "catch.hpp"

TEST_CASE("base shape") {
    auto basicCircle = Circle(1);

    SECTION("test boundingBox is correct size") {
        auto circleBox = basicCircle.getBoundingBox();
        auto correctBox = BoundingBox(2, 2);

        REQUIRE(circleBox == correctBox);
    }
}
