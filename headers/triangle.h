#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

#include <cstdlib>

class Triangle: public Polygon	{
public:
	Triangle(double sideLength);
	~Triangle() = default;
};

#endif //TRIANGLE_H
