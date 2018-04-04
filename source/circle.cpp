#include "../headers/circle.h"

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
    string psTemplate = R"ps(
        /inch {72 mul} def

        gsave
        8.5 inch 2 div 11 inch 2 div translate
        5 setlinewidth
        0 0 ${ radius }$ 0 360 arc closepath stroke
        grestore
    )ps";

    replaceWithValue("radius", psTemplate);

    return psTemplate;
}

void Circle::replaceWithValue(string token, string & psTemplate) const {
    auto formattedToken = "${ " + token + " }$";

    auto pos = psTemplate.find(formattedToken);
    int r = round(_radius);

    psTemplate.replace(
        pos,
        formattedToken.length(),
        to_string(r)
    );
}




