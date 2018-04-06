#include "../headers/triangle.h"
#include "catch.hpp"

#include <iostream>
#include <string>
using std::string;
#include <fstream>
using std::ofstream;

TEST_CASE("Triangles")	{
	auto triangle1 = Triangle(1);

	SECTION("Bounding box test for triangle") {
	}
}

TEST_CASE("Triangles: Draw to PostScript") {
	auto triangle = Triangle(5);
	string output = ""; // could do "/inch {72 mul} def\n\n\n\n" but we're not using doubles...
	SECTION("Can write output") {
		REQUIRE_NOTHROW(output = triangle.postscript(std::make_pair(0.0,0.0), output));
		ofstream of("../ps-example/test-triangle.ps");
		if (of.is_open()) {
			of << "Is this printing" << std::endl;
			of.close();
		}
	}
}
