#include "ATarget.hpp"

ATarget::ATarget(void) {}

ATarget::ATarget(std::string type) : type(type) {}

ATarget::ATarget(const ATarget& src)
{
	this->operator=(src);
}

ATarget::~ATarget(void) {}

ATarget& ATarget::operator=(const ATarget& src)
{
	type = src.type;
	return *this;
}

const std::string&	ATarget::getType(void) const
{
	return type;
}

void			ATarget::getHitsBySpell(const ASpell& spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

