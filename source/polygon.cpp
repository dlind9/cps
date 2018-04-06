#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using std::to_string;
#include "../headers/polygon.h"

Polygon::Polygon(const size_type & numSides, const size_type & sideLen)
	: Shape(),
    _numSides(numSides),
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

    setBoundingBox(makeBoundingBox());
}

BoundingBox Polygon::makeBoundingBox() {
    size_type width, height;

	if (fmod(_numSides,2)==1) {
		height = (_sideLen*(1+cos(M_PI/_numSides)))/(2*sin(M_PI/_numSides));
		width = (_sideLen*sin(M_PI_2*(_numSides-1)/(2*_numSides))/(sin(M_PI/_numSides)));
	}
	else if (fmod(_numSides,4)==0) {
		height = _sideLen*(cos(M_PI/_numSides))/(sin(M_PI/_numSides));
		width = (_sideLen*cos(M_PI/_numSides))/(sin(M_PI/_numSides));
	}
	else if (fmod(_numSides,2)==0) {
		height = _sideLen*(cos(M_PI/_numSides))/(sin(M_PI/_numSides));
		width = _sideLen/(sin(M_PI/_numSides));
	}
	else throw "An error hath!: unable to determine bounding box width and height";

    std::cout << width << ", " << height << std::endl;

    return BoundingBox(height, width);
}

const Polygon::size_type Polygon::getNumOfSides() const {
	return _numSides;
}

const Polygon::size_type Polygon::getLenOfSides() const {
	return _sideLen;
}

// takes a pair to choose point on page to draw on with (0,0)
// printing at bottom left, and a string
string Polygon::postscript() {
    auto box = getBoundingBox();
	size_type xStart = 0; //(box.width - _sideLen) / 2.;
	size_type yStart = 0; //_sideLen - (box.height / 2.);

    translate(-box.width / 2.,- box.height / 2.);

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

	size_type angle = 360 / _numSides;
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
