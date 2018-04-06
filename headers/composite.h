#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "shape.h"
#include "models.h"

#include <string>

class CompositeShape : public Shape {
    protected:
        ShapePtrs shapes;

    public:
        CompositeShape() = default;
        std::string postscript() const override;

        void add(ShapePtr shape);

    private:
        virtual std::string getCompositeShapePS() const = 0;
};

class StackedShape : public CompositeShape {
    public:
        std::string getCompositeShapePS() const;
};

#endif
