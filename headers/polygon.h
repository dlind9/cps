#ifndef POLYGON_H
#define POLYGON_H

#include <algorithm>
#include <cstdlib>
#include <string>
#include "shape.h"


class Polygon : public Shape {
	private:
		using size_type = size_t;
		const size_type _numSides, _sideLen;
		BoundingBox _boundBox;

	public:
		Polygon() = delete;
		Polygon(const size_type & numSides, const size_type & sideLen);
		~Polygon() override = default;

		// Compiler takes care of copy and move

		const size_type getNumOfSides() const;
		const size_type getLenOfSides() const;
		const BoundingBox getBoundingBox() const;
		virtual std::string postscript(std::string &, const size_type &, const size_type &);
};

bool operator==(const Polygon & lhs, const Polygon & rhs);

#endif // POLYGON_H
