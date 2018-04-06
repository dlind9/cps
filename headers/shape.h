#ifndef SHAPE_H
#define SHAPE_H

#include "models.h"

#include <memory>
#include <vector>

class Shape {
    private:
        Point _center;
        BoundingBox _boundingBox;

        std::string transformation;

    public:
        Shape()=default;
        virtual ~Shape() = default;

        virtual std::string postscript() const = 0;

        std::string getTransform() const;

        BoundingBox getBoundingBox() const;
        void setBoundingBox(BoundingBox b);

        void scale(double x, double y);
        void translate(double x, double y);
        void rotate(int ticks);
};

using ShapePtr = std::shared_ptr<Shape>;
using ShapePtrs = std::vector<ShapePtr>;

#endif // SHAPE_H
