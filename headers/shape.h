#ifndef SHAPE_H
#define SHAPE_H

#include "models.h"

class Shape {
    private:
        Point center;
        BoundingBox boundingBox;

    public:
        Shape()=default;
        Shape(const Point & center, const BoundingBox & boundingBox);
        virtual ~Shape() = default;

        virtual const BoundingBox getBoundingBox() const = 0;
};

#endif // SHAPE_H
