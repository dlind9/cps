#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <cstdlib>

class Circle : public Shape {
    private:
        size_t radius;

    public:
        Circle(int radius);
        ~Circle() override = default;

        BoundingBox getBoundingBox() override {
            return BoundingBox(2*radius, 2*radius);
        }
};

#endif // CIRLCE_H
