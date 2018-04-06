#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "shape.h"
#include "models.h"

#include <string>

class StackedShape : public Shape {
    private:
        ShapePtrs shapes;

    public:
        StackedShape() = default;
        std::string postscript() const override;

        void add(ShapePtr shape);

    private:
        std::string getStackedShapesPS() const;
};

#endif
