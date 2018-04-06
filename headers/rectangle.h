#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "shape.h"
#include "models.h"

class Rectangle : public Shape {
	BoundingBox _boundingBox;

    public:
        Rectangle(double width, double height);
        ~Rectangle() override = default;

		std::string postscript() const override;

        BoundingBox makeBoundingBox(double width, double height);
};

class Spacer : public Rectangle {
    public:
        Spacer(double width, double height);
        ~Spacer() override = default;
};

#endif
