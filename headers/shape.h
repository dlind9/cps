#ifndef SHAPE_H
#define SHAPE_H

#include "models.h"

class Shape {
    private:
        Point _center;
        BoundingBox _boundingBox;

        std::string transformation;

        void scale(Scale s);
        void translate(Translation t);
        void rotate(Rotation r);

    public:
        Shape()=default;
        virtual ~Shape() = default;
};


#endif // SHAPE_H
