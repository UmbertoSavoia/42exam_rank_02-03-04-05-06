#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(std::string name, std::string effects) : ASpell(name, effects) {}

Fwoosh::Fwoosh(const Fwoosh& src) : ASpell(src) {}

Fwoosh& Fwoosh::operator=(const Fwoosh& src)
{
	if (this != &src)
		*this = src;
	return *this;
}

Fwoosh::~Fwoosh(void) {}

ASpell*		Fwoosh::clone(void) const
{
	return (new Fwoosh(*this));
}
