#include "../headers/shape.h"
#include "../headers/models.h"

#include <string>
using std::to_string;

void Shape::scale(double x, double y) {
    transformation += StringTemplate("${x} ${y} scale\n")
        .replace("x", x)
        .replace("y", y)
        .get();
}

void Shape::translate(double x, double y) {
    transformation += StringTemplate("${x} ${y} translate\n")
        .replace("x", x)
        .replace("y", y)
        .get();
}

void Shape::rotate(int ticks) {
    auto degrees = 90. * ticks;

    transformation += StringTemplate("${degrees} rotate\n")
        .replace("degrees", degrees)
        .get();
}

std::string Shape::getTransform() const {
    return transformation;
}
