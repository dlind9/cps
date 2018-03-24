
#include "headers/circle.h"

Circle::Circle(int initialRadius):
    Shape(Point(), getBoundingBox()),
    radius(initialRadius) {
};


