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
        std::string getCompositeShapePS();
        virtual void adjustBoundingBox(BoundingBox &, const BoundingBox & box) = 0;
        virtual bool translationIsNeeded() = 0;
        virtual double compositeTranslation(const BoundingBox &, const BoundingBox &) = 0;
};

class LayeredShape : public CompositeShape {
    public:
        void adjustBoundingBox(BoundingBox &, const BoundingBox &) override;
        bool translationIsNeeded() override;
        double compositeTranslation(const BoundingBox & currBox, const BoundingBox & nextBox) override;
};

class HorizontalShape : public CompositeShape {
    public:
        void adjustBoundingBox(BoundingBox &, const BoundingBox &) override;
        bool translationIsNeeded() override;
        double compositeTranslation(const BoundingBox &, const BoundingBox &) override;
};

class VerticalShape : public CompositeShape {
    public:
        void adjustBoundingBox(BoundingBox &, const BoundingBox &) override;
        bool translationIsNeeded() override;
        double compositeTranslation(const BoundingBox &, const BoundingBox &) override;
};

using CompositePtr = std::shared_ptr<CompositeShape>;
class CustomShape : public HorizontalShape {
    public:
        CustomShape();
    private:

    CompositePtr addShapes(CompositePtr & composite);
};




#endif
