#include "headers/shape.h"

Shape::Shape(const Point & center, const BoundingBox & boundingBox) :
    center(center),
    boundingBox(boundingBox) {
};
