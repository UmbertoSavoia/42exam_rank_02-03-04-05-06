#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {}

Dummy::Dummy(std::string type) : ATarget(type) {}

Dummy::Dummy(const Dummy& src) : ATarget(src.getType()) {}

Dummy& Dummy::operator=(const Dummy& src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Dummy::~Dummy(void) {}

ATarget*	Dummy::clone(void) const
{
	return (new Dummy(*this));
}