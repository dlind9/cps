
#include "../headers/composite.h"

#include <string>
using std::string;
#include <iostream>
using std::endl;
using std::cout;
#include <algorithm>
using std::max;

string CompositeShape::postscript() {
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

string LayeredShape::getCompositeShapePS() {
    string total = "";

    for (const auto & shape : shapes) {
        total += shape->postscript();
    }

    return total;
}

string HorizontalShape::getCompositeShapePS() {
    string total = "";
    auto translation = 0.;
    BoundingBox newBox(0., 0.);

    auto size = shapes.size();
    for (size_t i = 0; i < size; ++i) {
        auto shape = shapes[i];
        auto box = shape->getBoundingBox();

        newBox.width += box.width;
        newBox.height = max(newBox.height, box.height);

        total += shape->postscript();

        if (i + 1 < size) {
            auto shapesWidth = box.width / 2;
            auto nextWidth = shapes[i+1]->getBoundingBox().width / 2;

            translation += (shapesWidth + nextWidth);
            shapes[i+1]->translate(-translation, 0);
        }
    }

    setBoundingBox(newBox);

    return total;
}
