#ifndef MODELS_H
#define MODELS_H

#include <cstdlib>
#include <ostream>
#include <string>


struct Point {
    double x, y;

    Point() = default;
    Point(double x, double y) : x(x), y(y) {}
};

class StringTemplate {
    private:
        std::string total;
    public:
        StringTemplate(std::string t);

        std::string get();
        StringTemplate& replaceTokenWithValue(const std::string & token, std::string value);
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
