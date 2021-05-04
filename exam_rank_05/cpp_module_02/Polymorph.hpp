#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph(void);
		Polymorph(std::string name, std::string effects);
		Polymorph(const Polymorph& src);
		virtual ~Polymorph(void);
		Polymorph& operator=(const Polymorph& src);

		ASpell*		clone(void) const;
};

#endif
