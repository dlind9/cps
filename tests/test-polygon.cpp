#define _USE_MATH_DEFINES

#include <cmath>

// Multiple inclusion tests
#include "../headers/polygon.h"
#include "../headers/polygon.h"
#include "../headers/models.h"
#include "../headers/models.h"

#include "catch.hpp"

bool resetOKFlag(bool & ok) {
	return ok = true;
}

TEST_CASE("Polygons: basic polygons") {
	// These shapes should be fine since number of sides is > 5 or default
	auto pentagon = Polygon(5,1);
	auto hexagon = Polygon(6,1);
	auto septagon = Polygon(7,1);
	auto octogon = Polygon(8,1);
	auto nonagon = Polygon(9,1);
	
	SECTION("test shapes have proper amount of sides") {
		REQUIRE(pentagon.getNumOfSides() == 5);
		REQUIRE(hexagon.getNumOfSides() == 6);
		REQUIRE(septagon.getNumOfSides() == 7);
		REQUIRE(octogon.getNumOfSides() == 8);
		REQUIRE(nonagon.getNumOfSides() == 9);
	}
	
	// These shapes should throw an exception and ask user to use something
	// other than a polygon
	auto ok = true;
	
	SECTION("illegal polygons") {
		try {
			auto badCircle = Polygon(1,1);
		}
		catch(...) {
			ok = false;
		}
		REQUIRE(ok == false);
		ok = resetOKFlag(ok);
		
		try {
			auto badTri = Polygon(3,1);
		}
		catch(...) {
			ok = false;
		}
		REQUIRE(ok == false);
		ok = resetOKFlag(ok);
		
		try {
			auto badSquare = Polygon(4,1);
		}
		catch(...) {
			ok = false;
		}
		REQUIRE(ok == false);
		ok = resetOKFlag(ok);
	}
}

int polyHeight(const int & n, const int & e) {
	if (n%2==1) 
		return e*(1+cos(M_PI/n)/(2*sin(M_PI/n)));
	else if (n%4==0) 
		return e*(cos(M_PI/n))/(sin(M_PI/n));
	else if (n%2==0 && n%4!=0) 
		return e*(cos(M_PI/n))/(sin(M_PI/n));
}

int polyWidth(const int & n, const int & e) {
	if (n%2==1) 
		return (e*sin(M_PI*(n-1)/2*n))/(sin(M_PI/n));
	else if (n%4==0) 
		return (e*cos(M_PI/n))/(sin(M_PI/n));
	else if (n%2==0 && n%4!=0) 
		return e/(sin(M_PI/n));
}

TEST_CASE("Polygons: bounding box correctness") {
	auto pentagon = Polygon(5,1);
	auto hexagon = Polygon(6,1);
	auto septagon = Polygon(7,1);
	auto octogon = Polygon(8,1);
	auto nonagon = Polygon(9,1);
	
	auto testPentaBox = BoundingBox(polyHeight(5,1), polyWidth(5,1));
	auto testHexaBox = BoundingBox(polyHeight(6,1), polyWidth(6,1));
	auto testSeptaBox = BoundingBox(polyHeight(7,1), polyWidth(7,1));
	auto testOctoBox = BoundingBox(polyHeight(8,1), polyWidth(8,1));
	auto testNonaBox = BoundingBox(polyHeight(9,1), polyWidth(9,1));
	
	SECTION("test shapes have proper bounding boxes") {
		REQUIRE(pentagon.getBoundingBox() == testPentaBox);
		REQUIRE(hexagon.getBoundingBox() == testHexaBox);
		REQUIRE(septagon.getBoundingBox() == testSeptaBox);
		REQUIRE(octogon.getBoundingBox() == testOctoBox);
		REQUIRE(nonagon.getBoundingBox() == testNonaBox);
	}
	
	auto bigpentagon = Polygon(5,2);
	auto bighexagon = Polygon(6,3);
	auto bigseptagon = Polygon(7,4);
	auto bigoctogon = Polygon(8,5);
	auto bignonagon = Polygon(9,6);
	
	auto bigtestPentaBox = BoundingBox(polyHeight(5,2), polyWidth(5,2));
	auto bigtestHexaBox = BoundingBox(polyHeight(6,3), polyWidth(6,3));
	auto bigtestSeptaBox = BoundingBox(polyHeight(7,4), polyWidth(7,4));
	auto bigtestOctoBox = BoundingBox(polyHeight(8,5), polyWidth(8,5));
	auto bigtestNonaBox = BoundingBox(polyHeight(9,6), polyWidth(9,6));
	
	SECTION("larger test shapes have proper bounding boxes") {
		REQUIRE(bigpentagon.getBoundingBox() == bigtestPentaBox);
		REQUIRE(bighexagon.getBoundingBox() == bigtestHexaBox);
		REQUIRE(bigseptagon.getBoundingBox() == bigtestSeptaBox);
		REQUIRE(bigoctogon.getBoundingBox() == bigtestOctoBox);
		REQUIRE(bignonagon.getBoundingBox() == bigtestNonaBox);
	}
}

TEST_CASE("Polygons: copiable") {
	auto pentagon = Polygon(5,1);
	auto hexagon = Polygon(6,1);
	auto septagon = Polygon(7,1);
	auto octogon = Polygon(8,1);
	auto nonagon = Polygon(9,1);

	auto pentaCopy = pentagon;
	auto hexaCopy = hexagon;
	auto septaCopy(septagon);
	auto octoCopy(octogon);
	auto nonaCopy = (nonagon);
	
	SECTION("test shapes are proper copies of shapes") {
		REQUIRE(pentagon == pentaCopy);
		REQUIRE(hexagon == hexaCopy);
		REQUIRE(septagon == septaCopy);
		REQUIRE(octogon == octoCopy);
		REQUIRE(nonagon == nonaCopy);
	}
}