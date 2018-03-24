#include "../headers/circle.h"
#include "../headers/circle.h"

#include "catch.hpp"

TEST_CASE("base shape") {
    auto basicCircle = Circle(1);
    REQUIRE_NOTHROW();
}
