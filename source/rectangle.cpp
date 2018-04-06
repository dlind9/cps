#include "../headers/rectangle.h"
#include "../headers/models.h"
#include "../headers/shape.h"

#include <string>
using std::string;
using std::to_string;


Rectangle::Rectangle(double width, double height)
	: _width(width),
	_height(height) {
	_boundingBox.width = width;
	_boundingBox.height = height;
}

std::string Rectangle::postscript() const {
    auto transforms = getTransform();

    string rectanglePs = R"ps(
        gsave

        ${transform}

        newpath
        -${width} 2 div -${height} 2 div
         ${width} ${height} rectstroke

        grestore
    )ps";

    string formattedPs = StringTemplate(rectanglePs)
        .replace("transform", transforms)
        .replace("width", _boundingBox.width)
        .replace("height", _boundingBox.height)
        .get();

	return formattedPs;
}

Spacer::Spacer(double width, double height): Rectangle(width, height) {}

