#define _USE_MATH_DEFINES

#include <cmath>

// Multiple inclusion tests
#include "../headers/scale.h"
#include "../headers/scale.h"
#include "../headers/scale.h"
#include "../headers/polygon.h"
#include "../headers/polygon.h"
#include "../headers/circle.h"
#include "../headers/circle.h"

#include "catch.hpp"

int polyBoxHeight(const int & n, const int & e) {
	if (n%2==1) 
		return e*(1+cos(M_PI/n)/(2*sin(M_PI/n)));
	else if (n%4==0) 
		return e*(cos(M_PI/n))/(sin(M_PI/n));
	else if (n%2==0 && n%4!=0) 
		return e*(cos(M_PI/n))/(sin(M_PI/n));
}

int polyBoxWidth(const int & n, const int & e) {
	if (n%2==1) 
		return (e*sin(M_PI*(n-1)/2*n))/(sin(M_PI/n));
	else if (n%4==0) 
		return (e*cos(M_PI/n))/(sin(M_PI/n));
	else if (n%2==0 && n%4!=0) 
		return e/(sin(M_PI/n));
}

TEST_CASE("Shapes: Scaling") {
	auto circle = Circle(1);
	auto pentagon = Polygon(5,1);
	auto hexagon = Polygon(6,1);
	auto septagon = Polygon(7,1);
	auto octogon = Polygon(8,1);
	auto nonagon = Polygon(9,1);
	
	//auto circle = Circle(1);
	auto doublePentaBox = BoundingBox(2*polyBoxHeight(5,1), 2*polyBoxWidth(5,1));
	auto quadHexaBox = BoundingBox(4*polyBoxHeight(6,1), 4*polyBoxWidth(6,1));
	auto doubleXSeptaBox = BoundingBox(polyBoxHeight(7,1), 2*polyBoxWidth(7,1));
	auto doubleYOctoBox = BoundingBox(2*polyBoxHeight(8,1), polyBoxWidth(8,1));
	//auto testNonaBox = BoundingBox(polyBoxHeight(9,1), polyBoxWidth(9,1));
	
	SECTION("test shapes are scaled properly") {
		// Double sized pentagon
		scale(pentagon, 2, 2);
		REQUIRE(pentagon.getBoundingBox() == doublePentaBox);
		
		// Quadruple sized hexagon
		scale(hexagon, 4, 4);
		REQUIRE(hexagon.getBoundingBox() == quadHexaBox);
		
		// Septagon with x doubled
		scale(septagon, 2, 1);
		REQUIRE(septagon.getBoundingBox() == doubleXSeptaBox);
		
		// Octogon with y doubled
		scale(octogon, 1, 2);
		REQUIRE(octogon.getBoundingBox() == doubleYOctoBox);
		//REQUIRE(nonagon == );
	}
}