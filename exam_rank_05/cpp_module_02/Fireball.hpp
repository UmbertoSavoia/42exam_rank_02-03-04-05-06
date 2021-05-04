#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball(void);
		Fireball(std::string name, std::string effects);
		Fireball(const Fireball& src);
		virtual ~Fireball(void);
		Fireball& operator=(const Fireball& src);

		virtual ASpell*		clone(void) const;
};

#endif
