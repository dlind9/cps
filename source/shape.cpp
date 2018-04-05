#include "../headers/shape.h"
#include "../headers/models.h"

#include <string>

void Shape::scale(double x, double y) {
    transformation += StringTemplate("${ x }$ ${ y }$ scale\n")
        .replaceTokenWithValue("x", std::to_string(x))
        .replaceTokenWithValue("y", std::to_string(y))
        .get();
}

void Shape::translate(double x, double y) {
    transformation += StringTemplate("${ x }$ ${ y }$ translate\n")
        .replaceTokenWithValue("x", std::to_string(x))
        .replaceTokenWithValue("y", std::to_string(y))
        .get();
}

void Shape::rotate(int ticks) {
    auto degrees = 90. * ticks;

    transformation += StringTemplate("${ degrees }$ rotate\n")
        .replaceTokenWithValue("degrees", std::to_string(degrees))
        .get();
}

std::string Shape::getTransform() const {
    return transformation;
}
