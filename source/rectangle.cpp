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
	
	outStream = outStream + "\n\n\n\ngsave\n";
	outStream = outStream + "newpath\n";
	outStream = outStream + to_string(xStart) + " " + to_string(yStart) + " moveto\n";
	outStream = outStream + to_string(_boundingBox.width) + " 0 rlineto\n";
	outStream = outStream + "0 " + to_string(_boundingBox.height) + " rlineto\n";
	outStream = outStream + to_string(-_boundingBox.width) + " 0 rlineto\n";
	outStream = outStream + "closepath\n";
	outStream = outStream + "stroke\n";
	outStream = outStream + "grestore\n\n\n\n";
	
	return outStream;
}

Spacer::Spacer(double width, double height): Rectangle(width, height) {}

