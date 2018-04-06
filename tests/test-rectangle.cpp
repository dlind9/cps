#include "../headers/rectangle.h"
#include "../headers/rectangle.h"
#include "../headers/models.h"

#include "catch.hpp"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ofstream;

TEST_CASE("rectangle") {
    vector<Rectangle> rects = {
        {1, 1}, {1, 2}, {1, 3},
        {2, 1}, {2, 2}, {2, 3},
        {3, 1}, {3, 2}, {3, 3}
    };

    vector<BoundingBox> boxes = {
        {1, 1}, {1, 2}, {1, 3},
        {2, 1}, {2, 2}, {2, 3},
        {3, 1}, {3, 2}, {3, 3}
    };

    SECTION("test that the bounding box is correct") {
        for (size_t i = 0; i < boxes.size(); ++i) {
            //REQUIRE(rects[i].getBoundingBox() == boxes[i]);
        }
    }
}

TEST_CASE("Rectangles: Draw to PostScript") {
	auto rectangle = Rectangle(8,4);
    string correct = R"ps(
        gsave
        newpath
        192.000000 196.000000 moveto
        8.000000 0 rlineto
        0 4.000000 rlineto
        -8.000000 0 rlineto
        closepath
        stroke
        grestore
    )ps";

	SECTION("Can write output") {
        string output;

		REQUIRE_NOTHROW(output = rectangle.postscript(output, 200, 200));
        REQUIRE(output == correct);

		ofstream of("ps-example/test-rectangle.ps");
		if (of.is_open()) {
			of << output << std::endl;
			of.close();
		}
	}
}
