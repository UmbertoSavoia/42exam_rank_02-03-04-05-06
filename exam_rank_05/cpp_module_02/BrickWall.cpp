#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall(std::string type) : ATarget(type) {}

BrickWall::BrickWall(const BrickWall& src) : ATarget(src.getType()) {}

BrickWall& BrickWall::operator=(const BrickWall& src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

BrickWall::~BrickWall(void) {}

ATarget*	BrickWall::clone(void) const
{
	return (new BrickWall(*this));
}
