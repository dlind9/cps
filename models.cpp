#include "headers/models.h"

bool operator==(const BoundingBox & lhs, const BoundingBox & rhs) {
    return rhs._height == lhs._height and
        rhs._height == lhs._width;
}
