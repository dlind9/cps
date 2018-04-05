#ifndef MODELS_H
#define MODELS_H

#include <cstdlib>
#include <ostream>
#include <string>

struct Transformation {
    virtual std::string postscript() = 0;
};

struct XYPair : Transformation {
    double x, y;

    XYPair() = default;
    XYPair(double x, double y) : Transformation(), x(x), y(y) {}
};

struct Scale : XYPair {
    Scale(double x, double y) : XYPair(x, y) {}

    std::string postscript() override {
        return std::to_string(x) + " " + std::to_string(y) + " scale\n";
    }
};

struct Translation : XYPair {
    Translation(double x, double y) : XYPair(x, y) {}

    std::string postscript() override {
        return std::to_string(x) + " " + std::to_string(y) + " translate\n";
    }
};

struct Rotation : Transformation {
    int ticks;

    Rotation(int ticks):
        ticks(ticks) {}

    std::string postscript() override {
        auto degrees = 90. * ticks;

        return std::to_string(degrees) + " rotate\n";
    }
};


struct Point {
    double x, y;

    Point() = default;
    Point(double x, double y) : x(x), y(y) {}
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
