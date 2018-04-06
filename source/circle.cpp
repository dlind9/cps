#include "../headers/circle.h"
#include "../headers/models.h"

#include <string>
using std::string;
using std::to_string;
#include <cmath>
using std::round;

#include <iostream>

Circle::Circle(double r):
    _radius(r) {
};

const BoundingBox Circle::getBoundingBox() const {
    return BoundingBox(_radius * 2, _radius * 2);
}

string Circle::postscript() const {
    int r = round(_radius);
    std::string transforms = this->getTransform();

    std::string circlePsText = R"ps(
        gsave

        ${ transformations }$

        1 setlinewidth
        0 0 ${ radius }$ 0 360 arc closepath stroke

        grestore
    )ps";

    auto formattedPsOutput = StringTemplate(circlePsText)
        .replace("transformations", transforms)
        .replace("radius", to_string(r))
        .get();

    return formattedPsOutput;
}





