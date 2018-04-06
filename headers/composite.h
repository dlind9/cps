#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "shape.h"

class VerticalShape : public Shape {
    private:
        ShapePtrs shapes;

        std::string postscript() const override {return "";}
    public:
        VerticalShape()=default;
};

#endif
