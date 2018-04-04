#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <cstdlib>
#include <string>

class Circle : public Shape {
    private:
        double _radius;

    public:
        Circle(double radius);
        ~Circle() override = default;

        std::string postscript() const;
        void replaceWithValue(
            std::string token,
            std::string & psTemplate
        ) const;

        const BoundingBox getBoundingBox() const;
};

#endif // CIRLCE_H
