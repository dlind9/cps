#include "../headers/composite.h"
#include "../headers/composite.h"
#include "../headers/circle.h"
#include "../headers/rectangle.h"
#include "../headers/polygon.h"

#include "catch.hpp"

#include <memory>
using std::make_shared;
#include <string>
#include <fstream>
using std::ofstream;
#include <iostream>
using std::endl;
using std::cout;

void toFile(const std::string & fname, const std::string & output) {
        ofstream of(fname);
        if (of.is_open()) {
            of << output << std::endl;
            of.close();
        }
}

CompositePtr addShapes(CompositePtr & composite) {
    for (auto i = 10; i < 50; i += 10) {
        auto c = make_shared<Circle>(i);
        auto r = make_shared<Rectangle>(i, i + 10);
        auto p = make_shared<Polygon>((i / 10) + 2, 30);
        composite->add(r);
        composite->add(c);
        composite->add(p);
    }

    composite->translate(200, 300);
    //composite->rotate(-2);

    return composite;
}

TEST_CASE("test composites") {
    SECTION("layered") {
        CompositePtr ss = make_shared<LayeredShape>();

        ss = addShapes(ss);

        std::string out = "";

        REQUIRE_NOTHROW(out = ss->postscript());

        toFile("ps-example/test-stacked.ps", out);
    }

    SECTION("horizontal") {
        CompositePtr hs = make_shared<HorizontalShape>();

        hs = addShapes(hs);
        std::string out = "";

        REQUIRE_NOTHROW(out = hs->postscript());

        toFile("ps-example/test-horizontal.ps", out);
    }
}
