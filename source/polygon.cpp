#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using std::to_string;
#include "../headers/polygon.h"

Polygon::Polygon(const size_type & numSides, const size_type & sideLen)
	:_numSides(numSides),
	_sideLen(sideLen) {
	if (numSides < 2) {
		string err = "ERROR: Polygon cannot have less than 5 sides! Did you mean: ";
		if (numSides == 1)
			err = err + "Circle?";
		else if (numSides == 0)
			err = err + "Spacer?";
		else
			err = err + "undefined shape";
		throw err;
	}

	if (fmod(numSides,2)==1) {
		_boundBox.height = (sideLen*(1+cos(M_PI/numSides)))/(2*sin(M_PI/numSides));
		_boundBox.width = (sideLen*sin(M_PI*(numSides-1)/(2*numSides))/(sin(M_PI/numSides)));
	}
	else if (fmod(numSides,4)==0) {
		_boundBox.height = sideLen*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_boundBox.width = (sideLen*cos(M_PI/numSides))/(sin(M_PI/numSides));
	}
	else if (fmod(numSides,2)==0) {
		_boundBox.height = sideLen*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_boundBox.width = sideLen/(sin(M_PI/numSides));
	}
	else throw "An error hath!: unable to determine bounding box width and height";
}

const Polygon::size_type Polygon::getNumOfSides() const {
	return _numSides;
}

const Polygon::size_type Polygon::getLenOfSides() const {
	return _sideLen;
}

const BoundingBox Polygon::getBoundingBox() const {
	return _boundBox;
}

string Polygon::postscript() const {
	size_t xStart = ((_boundBox.width-_sideLen)/2);
	size_t yStart = 1;

    string polygonPsText = R"ps(
        gsave

        ${transform}

        newpath
        ${x} ${y} moveto
        ${poly-path}
        stroke
        grestore
    )ps";

    auto formattedPs = StringTemplate(polygonPsText)
        .replace("transform", getTransform())
        .replace("x", xStart)
        .replace("y", yStart)
        .replace("poly-path", getPolyPath())
        .get();

	return formattedPs;
}

string Polygon::getPolyPath() const {
    string polyPath = "";

	size_t angle = 360 / _numSides;
	for(size_t i = 0; i < _numSides; ++i) {
        string polyPathText = R"ps(
            ${side-length} 0 rlineto
            ${angle} rotate
        )ps";

        polyPath += StringTemplate(polyPathText)
            .replace("side-length", _sideLen)
            .replace("angle", angle)
            .get();
	}

    return polyPath;
}

bool operator==(const Polygon & lhs, const Polygon & rhs) {
	return lhs.getNumOfSides() == rhs.getNumOfSides() &&
		lhs.getLenOfSides() == rhs.getLenOfSides() &&
		lhs.getBoundingBox() == rhs.getBoundingBox();
}
