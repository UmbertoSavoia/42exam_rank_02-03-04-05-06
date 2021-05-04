#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string name;
		std::string effects;

	public:
		ASpell(void);
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell& src);
		virtual ~ASpell(void);
		ASpell& operator=(const ASpell& src);

		std::string			getName(void) const;
		std::string			getEffects(void) const;
		virtual ASpell*		clone(void) const = 0;
		void				launch(const ATarget& target) const;
};

#endif
