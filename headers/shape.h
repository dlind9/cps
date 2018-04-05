#ifndef SHAPE_H
#define SHAPE_H

#include "models.h"

class Shape {
    private:
        Point _center;
        BoundingBox _boundingBox;

        std::string transformation;

    public:
        Shape()=default;
        virtual ~Shape() = default;

        std::string getTransform() const;

        Shape& scale(double x, double y);
        Shape& translate(double x, double y);
        Shape& rotate(int ticks);
};


#endif // SHAPE_H
