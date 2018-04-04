#include "../headers/triangle.h"
#include "catch.hpp"

#include <iostream>
#include <string>
using std::string;

TEST_CASE("Triangles")	{
	auto triangle1 = Triangle(1);

	SECTION("Bounding box test for triangle") {
		auto triangleBox = triangle1.getBoundingBox();

		//REQUIRE(triangleBox == BoundingBox(1,1));
	}
}

TEST_CASE("Triangles: Draw to PostScript") {
	auto triangle = Triangle(5);
	string output = ""; // could do "/inch {72 mul} def\n\n\n\n" but we're not using doubles...
	SECTION("Can write output") {
		REQUIRE_NOTHROW(output = triangle.postscript(output, 200, 200));
	}
}