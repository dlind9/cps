#ifndef POLYGON_H
#define POLYGON_H

#include <algorithm>
#include <cstdlib>
#include <string>
#include "shape.h"

class Polygon : public Shape {
	private:
		using size_type = double;
		const size_type _numSides, _sideLen;
		BoundingBox _boundBox;

	public:
		Polygon() = delete;
		Polygon(const size_type & numSides, const size_type & sideLen);
		~Polygon() override = default;

		const size_type getNumOfSides() const;
		const size_type getLenOfSides() const;
		const BoundingBox getBoundingBox() const;

		virtual std::string postscript(std::string &);
};

bool operator==(const Polygon & lhs, const Polygon & rhs);

#endif // POLYGON_H
