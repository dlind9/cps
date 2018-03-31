
#include "headers/circle.h"

Circle::Circle(int initialRadius):
    Shape(Point(), getBoundingBox()),
    radius(initialRadius) {
};

const BoundingBox Circle::getBoundingBox() const {
	return BoundingBox(2*radius, 2*radius);
}

const size_t Circle::getSize() const {
	return radius;
}

void Circle::setSize(const size_t & fx, const size_t & fy) {
	// TODO: Writeit!
}