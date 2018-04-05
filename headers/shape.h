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

        void scale(double x, double y);
        void translate(double x, double y);
        void rotate(int ticks);
};


#endif // SHAPE_H
