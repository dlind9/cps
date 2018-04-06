
#include "../headers/composite.h"

#include <string>
using std::string;
#include <iostream>
using std::endl;
using std::cout;

string StackedShape::postscript() const {
    auto stackedPsText = R"ps(
        gsave

        ${transform}
        ${stacked-shapes}

        grestore
    )ps";

    auto stackedShapes = getStackedShapesPS();

    auto formatted = StringTemplate(stackedPsText)
        .replace("transform", getTransform())
        .replace("stacked-shapes", stackedShapes)
        .get();

    return formatted;
}

void StackedShape::add(ShapePtr shape) {
    shapes.push_back(shape);
}

string StackedShape::getStackedShapesPS() const {
    string total = "";

    for (const auto & shape : shapes) {
        total += shape->postscript();
    }

    return total;
}
