#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
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

// takes a pair to choose point on page to draw on with (0,0)
// printing at bottom left, and a string
string Polygon::postscript(const std::pair<double, double> & startPos, string & outStream) {
	size_t xStart = startPos.first;
	size_t yStart = startPos.second;
	size_t angle = 360 / _numSides;

	outStream += "\n\n\n\ngsave\n";
	outStream += "newpath\n";
	outStream += to_string(xStart) + " " + to_string(yStart) + " moveto\n";
	for(size_t i = 0; i < _numSides; ++i) {
		outStream += to_string(_sideLen) + " " + to_string(0) + " rlineto\n";
		outStream +=  to_string(angle) + " rotate\n";
	}
	outStream += "stroke\n";
	outStream += "grestore\n\n\n\n";

	return outStream;
}

bool operator==(const Polygon & lhs, const Polygon & rhs) {
	return lhs.getNumOfSides() == rhs.getNumOfSides() &&
		lhs.getLenOfSides() == rhs.getLenOfSides() &&
		lhs.getBoundingBox() == rhs.getBoundingBox();
}
