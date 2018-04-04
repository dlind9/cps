#ifndef MODELS_H
#define MODELS_H

#include <cstdlib>
#include <ostream>
#include <string>

struct Point {
    int x, y;

    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
};

struct BoundingBox {
    double height, width;

    BoundingBox() = default;
    BoundingBox(double h, double w): height(h), width(w) {}

    std::string toString() const;
};

bool operator==(const BoundingBox & lhs, const BoundingBox & rhs);
std::ostream& operator <<(std::ostream& os, const BoundingBox & value);
#endif // MODELS_H
