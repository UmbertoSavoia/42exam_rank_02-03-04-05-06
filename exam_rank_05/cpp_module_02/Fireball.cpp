#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball(std::string name, std::string effects) : ASpell(name, effects) {}

Fireball::Fireball(const Fireball& src) : ASpell(src) {}

Fireball& Fireball::operator=(const Fireball& src)
{
	if (this != &src)
		*this = src;
	return *this;
}

Fireball::~Fireball(void) {}

ASpell*		Fireball::clone(void) const
{
	return (new Fireball(*this));
}
