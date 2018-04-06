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

std::string Rectangle::postscript(std::string & outStream, const size_type & x, const size_type & y) {
	double xStart = x - _boundingBox.width;
	double yStart = y - _boundingBox.height;

    string rectanglePs = R"ps(
        gsave
        newpath
        ${x} ${y} moveto
        ${width} 0 rlineto
        0 ${height} rlineto
        -${width} 0 rlineto
        closepath
        stroke
        grestore
    )ps";

    string formattedPs = StringTemplate(rectanglePs)
        .replace("x", xStart)
        .replace("y", yStart)
        .replace("width", _boundingBox.width)
        .replace("height", _boundingBox.height)
        .get();

	return formattedPs;
}

Spacer::Spacer(double width, double height): Rectangle(width, height) {}

