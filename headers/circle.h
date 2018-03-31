#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <cstdlib>

class Circle : public Shape {
    private:
        size_t radius;

    public:
        Circle(int radius);
        ~Circle() override = default;

        const BoundingBox getBoundingBox() const override;
		const size_t getSize() const override;
		void setSize(const size_t &, const size_t &) override;
};

#endif // CIRLCE_H
