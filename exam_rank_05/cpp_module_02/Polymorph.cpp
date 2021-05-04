#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph(std::string name, std::string effects) : ASpell(name, effects) {}

Polymorph::Polymorph(const Polymorph& src) : ASpell(src) {}

Polymorph& Polymorph::operator=(const Polymorph& src)
{
	if (this != &src)
		*this = src;
	return *this;
}

Polymorph::~Polymorph(void) {}

ASpell*		Polymorph::clone(void) const
{
	return (new Polymorph(*this));
}
