
#include "../headers/composite.h"
#include "../headers/polygon.h"
#include "../headers/circle.h"


#include <string>
using std::string;
#include <iostream>
using std::endl;
using std::cout;
#include <algorithm>
using std::max;
#include <memory>
using std::make_shared;

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

void LayeredShape::adjustBoundingBox(BoundingBox & newBox, const BoundingBox & box)  {
    newBox.width = max(newBox.width, box.width);
    newBox.height = max(newBox.height, box.height);
}

void HorizontalShape::adjustBoundingBox(BoundingBox & newBox, const BoundingBox & box)  {
    newBox.width += box.width;
    newBox.height = max(newBox.height, box.height);
}

void VerticalShape::adjustBoundingBox(BoundingBox & newBox, const BoundingBox & box)  {
    newBox.width = max(newBox.width, box.width);
    newBox.height += box.height;
}

bool LayeredShape::translationIsNeeded()  {
    return false;
}

bool HorizontalShape::translationIsNeeded()  {
    return true;
}

bool VerticalShape::translationIsNeeded()  {
    return true;
}

double HorizontalShape::compositeTranslation(const BoundingBox & currBox, const BoundingBox & nextBox) {
    auto shapesWidth = currBox.width / 2;
    auto nextWidth = nextBox.width / 2;
    return (shapesWidth + nextWidth);
}

double VerticalShape::compositeTranslation(const BoundingBox & currBox, const BoundingBox & nextBox) {
    auto shapesHeight = currBox.height / 2;
    auto nextHeight = nextBox.height / 2;
    return (shapesHeight + nextHeight);
}

double LayeredShape::compositeTranslation(const BoundingBox & currBox, const BoundingBox & nextBox) {
    return 0;
}

std::string CompositeShape::getCompositeShapePS() {
    string total = "";
    auto translation = 0.;
    BoundingBox newBox(0., 0.);

    auto size = shapes.size();
    for (size_t i = 0; i < size; ++i) {
        auto box = shapes[i]->getBoundingBox();

        adjustBoundingBox(newBox, box);

        total += shapes[i]->postscript();
        if (translationIsNeeded())    {
           if (i + 1 < size) {
                translation += compositeTranslation(box, (shapes[i+1]->getBoundingBox()));
                shapes[i+1]->translate(0, -translation);
            }
        }

    }

    setBoundingBox(newBox);

    return total;
}

CompositePtr CustomShape::addShapes(CompositePtr & composite) {
    for (auto i = 10; i < 40; i += 10) {
        auto c = make_shared<Polygon>(i / 10 + 2, i);
        auto r = make_shared<Circle>(i);
        composite->add(c);
        composite->add(r);
    }

    composite->translate(200, 300);
    composite->rotate(-2);

    return composite;
}


CustomShape::CustomShape(): HorizontalShape() {
        CompositePtr stacked = make_shared<LayeredShape>();
        CompositePtr vertical = make_shared<VerticalShape>();
        CompositePtr horizontal = make_shared<HorizontalShape>();

        stacked = addShapes(stacked);
        vertical = addShapes(vertical);
        horizontal = addShapes(horizontal);

        add(stacked);
        add(vertical);
        add(horizontal);
}

