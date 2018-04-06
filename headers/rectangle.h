#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "shape.h"
#include "models.h"

class Rectangle : public Shape {
    using size_type = double;
	size_type _width, _height;
	BoundingBox _boundingBox;

    public:
        Rectangle(double width, double height);
        ~Rectangle() override = default;

		std::string postscript(std::string &, const size_type &, const size_type &);
};

class Spacer : public Rectangle {
    public:
        Spacer(double width, double height);
        ~Spacer() override = default;
};

#endif
