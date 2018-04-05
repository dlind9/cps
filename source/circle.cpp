#include "../headers/circle.h"
#include "../headers/models.h"

#include <string>
using std::string;
using std::to_string;
#include <cmath>
using std::round;

Circle::Circle(double r):
    _radius(r) {
};

const BoundingBox Circle::getBoundingBox() const {
    return BoundingBox(_radius * 2, _radius * 2);
}

string Circle::postscript() const {

    int r = round(_radius);
    auto transforms = this->getTransform();

    std::string circlePsText = R"ps(
        gsave

        ${ transformations }$

        8.5 inch 2 div 11 72 mul inch 2 72 mul div translate
        5 setlinewidth
        0 0 ${ radius }$ 0 360 arc closepath stroke
        grestore
    )ps";

    auto formattedPsOutput = StringTemplate(circlePsText)
        .replaceTokenWithValue("radius", to_string(r))
        .replaceTokenWithValue("transformations", transforms)
        .get();

    return formattedPsOutput;
}





