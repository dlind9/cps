#ifndef MODELS_H
#define MODELS_H

#include <cstdlib>

struct Point {
    int _x, _y;

    Point(int xInit=0, int yInit=0) : _x(xInit), _y(yInit) {}
};

struct BoundingBox {
    size_t _height, _width;

    BoundingBox() = default;
    BoundingBox(size_t initialHeight, size_t initialWidth): _height(initialHeight), _width(initialWidth) {}
};

bool operator==(const BoundingBox & lhs, const BoundingBox & rhs);

#endif // MODELS_H
