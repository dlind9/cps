#ifndef SCALE_H
#define SCALE_H

#include "shape.h"
#include <cstdlib>

template <typename Shape>
void scale(Shape shape, size_t fx, size_t fy) {
	shape.scaleShape(fx, fy);
}

#endif //SCALE_H
