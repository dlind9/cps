#ifndef POLYGON_H
#define POLYGON_H

#include <algorithm>
#include <cstdlib>
#include "shape.h"

class Polygon : public Shape {
	private:
		const size_t _numSides, _sideLen;
		BoundingBox _boundBox;

	public:
		Polygon() = delete;
		Polygon(const size_t & numSides, const size_t & sideLen);
		~Polygon() override = default;
		
		// Compiler takes care of copy and move
		
		// Inherited member functions
		const BoundingBox getBoundingBox() const override;
		const size_t getSize() const override;
		void setSize(const size_t &, const size_t &) override;
		
		// Shape specific member functions
		const size_t getNumOfSides() const;
};

// intended for debug only
bool operator==(const Polygon & lhs, const Polygon & rhs);

#endif // POLYGON_H