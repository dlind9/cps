#include "../headers/shape.h"


void Shape::scale(double x, double y) {
     transformation += std::to_string(x) + " " + std::to_string(y) + " scale\n";
}

void Shape::translate(double x, double y) {
     transformation += std::to_string(x) + " " + std::to_string(y) + " translate\n";
}

void Shape::rotate(int ticks) {
    auto degrees = 90. * ticks;

    transformation += std::to_string(degrees) + " rotate\n";
}

std::string Shape::getTransform() {
    return transformation;
}
