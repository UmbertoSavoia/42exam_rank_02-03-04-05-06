#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh(void);
		Fwoosh(std::string name, std::string effects);
		Fwoosh(const Fwoosh& src);
		virtual ~Fwoosh(void);
		Fwoosh& operator=(const Fwoosh& src);

		virtual ASpell*		clone(void) const;
};

#endif