
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
    BoundingBox newBox(0, 0);

    for (const auto & shape : shapes) {
        auto box = shape->getBoundingBox();

        newBox.width = max(newBox.width, box.width);
        newBox.height = max(newBox.height, box.height);

        total += shape->postscript();
    }

    setBoundingBox(newBox);

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


std::string VerticalShape::getCompositeShapePS() {
    string total = "";
    auto translation = 0.;
    BoundingBox newBox(0., 0.);

    auto size = shapes.size();
    for (size_t i = 0; i < size; ++i) {
        auto shape = shapes[i];
        auto box = shape->getBoundingBox();

        newBox.height += box.height;
        newBox.width = max(newBox.width, box.width);

        total += shape->postscript();

        if (i + 1 < size) {
            auto shapesHeight = box.height / 2;
            auto nextHeight = shapes[i+1]->getBoundingBox().height / 2;

            translation += (shapesHeight + nextHeight);
            shapes[i+1]->translate(0, -translation);
        }
    }

    setBoundingBox(newBox);

    return total;
}
