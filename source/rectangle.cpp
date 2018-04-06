#include "../headers/rectangle.h"
#include "../headers/models.h"
#include "../headers/shape.h"

#include <iostream>
#include <string>
using std::string;
using std::to_string;


Rectangle::Rectangle(double width, double height)
	: Shape() {
    setBoundingBox(makeBoundingBox(width, height));
}

BoundingBox Rectangle::makeBoundingBox(double width, double height) {
    return BoundingBox(height, width);
}

std::string Rectangle::postscript() {
    auto transforms = getTransform();
    auto box = getBoundingBox();

    std::cout << box.width << std::endl;

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
        .replace("width", box.width)
        .replace("height", box.height)
        .get();

	return formattedPs;
}

Spacer::Spacer(double width, double height): Rectangle(width, height) {}

std::string Spacer::postscript() {
    return "\n";
}

