
#include "../headers/composite.h"

#include <string>
using std::string;
#include <iostream>
using std::endl;
using std::cout;

string CompositeShape::postscript() const {
    auto stackedPsText = R"ps(
        gsave

        ${transform}
        ${stacked-shapes}

        grestore
    )ps";

    auto stackedShapes = getCompositeShapePS();

    auto formatted = StringTemplate(stackedPsText)
        .replace("transform", getTransform())
        .replace("stacked-shapes", stackedShapes)
        .get();

    return formatted;
}

void CompositeShape::add(ShapePtr shape) {
    shapes.push_back(shape);
}

string LayeredShape::getCompositeShapePS() const {
    string total = "";

    for (const auto & shape : shapes) {
        total += shape->postscript();
    }

    return total;
}

string HorizontalShape::getCompositeShapePS() const {
    string total = "";

    auto size = shapes.size();
    for (size_t i = 0; i < size; ++i) {
        total += shapes[i]->postscript();


        if (i < size - 1) {
            auto previousShapesWidth = shapes[i]->getBoundingBox().width;
            cout << previousShapesWidth << endl;
            shapes[i+1]->translate(previousShapesWidth, 0);
        }
    }

    return total;
}
