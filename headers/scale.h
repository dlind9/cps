#ifndef SCALE_H
#define SCALE_H

#include "shape.h"

template <typename Shape>
void scale(Shape shape, int fx, int fy) {
	shape.setSize(fx, fy);
}

#endif //SCALE_H