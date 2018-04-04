#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <string>
using std::string;
using std::to_string;
#include "../headers/polygon.h"

Polygon::Polygon(const size_t & numSides, const size_t & sideLen)
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

	if (numSides%2==1) {
		_boundBox.height = sideLen*(1+cos(M_PI/numSides)/(2*sin(M_PI/numSides)));
		_boundBox.width = (sideLen*sin(M_PI*(numSides-1)/2*numSides))/(sin(M_PI/numSides));
	}
	else if (numSides%4==0) {
		_boundBox.height = sideLen*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_boundBox.width = (sideLen*cos(M_PI/numSides))/(sin(M_PI/numSides));
	}
	else if (numSides%2==0 && numSides%4!=0) {
		_boundBox.height = sideLen*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_boundBox.width = sideLen/(sin(M_PI/numSides));
	}
	else throw "An error hath!: unable to determine bounding box width and height";
}

const size_t Polygon::getNumOfSides() const {
	return _numSides;
}

const size_t Polygon::getLenOfSides() const {
	return _sideLen;
}

const BoundingBox Polygon::getBoundingBox() const {
	return _boundBox;
}

string Polygon::postscript(string & outStream, const size_t & x, const size_t & y) {
	size_t xStart = x - _sideLen;
	size_t yStart = y - _boundBox.height;
	size_t angle = 360 / _numSides;
	
	outStream = outStream + "\n\n\n\ngsave\n";
	outStream = outStream + "newpath\n";
	outStream = outStream + to_string(xStart) + " " + to_string(yStart) + " moveto\n";
	for(auto i = 0; i < _numSides; ++i) {
		outStream = outStream + to_string(_sideLen) + " " + to_string(0) + " rlineto\n";
		outStream = outStream + to_string(angle) + " rotate\n";
	}
	outStream = outStream + "stroke\n";
	outStream = outStream + "restore\n\n\n\n";
	
	return outStream;
}

bool operator==(const Polygon & lhs, const Polygon & rhs) {
	return lhs.getNumOfSides() == rhs.getNumOfSides() &&
		lhs.getLenOfSides() == rhs.getLenOfSides() &&
		lhs.getBoundingBox() == rhs.getBoundingBox();
}