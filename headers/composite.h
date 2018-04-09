#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "shape.h"
#include "models.h"

#include <string>
#include <memory>


class CompositeShape : public Shape {
    protected:
        ShapePtrs shapes;

    public:
        CompositeShape() = default;
        std::string postscript() override;

        void add(ShapePtr shape);

    private:
        virtual std::string getCompositeShapePS() = 0;
};

class LayeredShape : public CompositeShape {
    public:
        std::string getCompositeShapePS() override;
};

class HorizontalShape : public CompositeShape {
    public:
        std::string getCompositeShapePS() override;
};

class VerticalShape : public CompositeShape {
    public:
        std::string getCompositeShapePS() override;
};

using CompositePtr = std::shared_ptr<CompositeShape>;
class CustomShape : public HorizontalShape {
    public:
        CustomShape();
    private:

    CompositePtr addShapes(CompositePtr & composite);
};




#endif
