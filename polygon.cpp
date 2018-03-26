#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <string>
using std::string;
#include "headers/polygon.h"

Polygon::Polygon(const size_t & numSides, const size_t & sideLen)
	:_numSides(numSides),
	_sideLen(sideLen) {
	if (numSides < 5) {
		string err = "ERROR: Polygon cannot have less than 5 sides! Did you mean: ";
		if (numSides == 4)
			err = err + "Square/Rectangle?";
		else if (numSides == 3)
			err = err + "Triangle?";
		else if (numSides == 1)
			err = err + "Circle?";
		else if (numSides == 0)
			err = err + "Spacer?";
		else 
			err = err + "undefined shape";
		throw err;
	}
	
	if (numSides%2==1) {
		_boundBox._height = sideLen*(1+cos(M_PI/numSides)/(2*sin(M_PI/numSides)));
		_boundBox._width = (sideLen*sin(M_PI*(numSides-1)/2*numSides))/(sin(M_PI/numSides));
	} 
	else if (numSides%4==0) {
		_boundBox._height = sideLen*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_boundBox._width = (sideLen*cos(M_PI/numSides))/(sin(M_PI/numSides));
	}
	else if (numSides%2==0 && numSides%4!=0) {
		_boundBox._height = sideLen*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_boundBox._width = sideLen/(sin(M_PI/numSides));
	}
	else throw "An error hath!: unable to determine bounding box width and height";
}

/* Polygon::Polygon(const Polygon & other)
	:_numSides(other._numSides),
	_sideLen(other._sideLen),
	_boundBox(other._boundBox) {}

Polygon Polygon::operator=(const Polygon & other) {
	Polygon copyPolygon(other);
	swap(copyPolygon);
	return *this;
} */

const size_t Polygon::getNumOfSides() const {
	return _numSides;
}

const size_t Polygon::getLenOfSides() const {
	return _sideLen;
}

const BoundingBox Polygon::getBoundingBox() const {
	return _boundBox;
}

bool operator==(const Polygon & lhs, const Polygon & rhs) {
	return lhs.getNumOfSides() == rhs.getNumOfSides() &&
		lhs.getLenOfSides() == rhs.getLenOfSides() &&
		lhs.getBoundingBox() == rhs.getBoundingBox();
}