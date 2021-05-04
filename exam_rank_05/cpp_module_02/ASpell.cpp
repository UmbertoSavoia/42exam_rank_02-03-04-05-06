#include "ASpell.hpp"

ASpell::ASpell(void) {};

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects) {};

ASpell::ASpell(const ASpell& src)
{
	this->operator=(src);
}

ASpell::~ASpell(void) {};

ASpell& ASpell::operator=(const ASpell& src)
{
	name = src.name;
	effects = src.effects;
	return *this;
}

std::string		ASpell::getName(void) const
{
	return name;
}

std::string		ASpell::getEffects(void) const
{
	return effects;
}

void			ASpell::launch(const ATarget& target) const
{
	target.getHitsBySpell(*this);
}

