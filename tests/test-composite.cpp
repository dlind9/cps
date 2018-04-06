#include "../headers/composite.h"
#include "../headers/composite.h"
#include "../headers/circle.h"
#include "../headers/rectangle.h"

#include "catch.hpp"

#include <memory>
using std::make_shared;
#include <string>
#include <fstream>
using std::ofstream;
#include <iostream>
using std::endl;
using std::cout;

TEST_CASE("test composites") {
    StackedShape ss;

    for (auto i = 10; i < 50; i += 10) {
        auto c = make_shared<Circle>(i);
        auto r = make_shared<Rectangle>(i, i + 10);
        ss.add(r);
        ss.add(c);
    }

    ss.translate(200, 300);


    std::string out = "";

    REQUIRE_NOTHROW(out = ss.postscript());

    ofstream of("ps-example/test-stacked.ps");
    if (of.is_open()) {
        of << out << std::endl;
        of.close();
    }

}
