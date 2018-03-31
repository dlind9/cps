#ifndef SHAPE_H
#define SHAPE_H

#include <cstdlib>
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
		virtual const size_t getSize() const = 0;
		virtual void setSize(const size_t &, const size_t &) = 0;
};

#endif // SHAPE_H
