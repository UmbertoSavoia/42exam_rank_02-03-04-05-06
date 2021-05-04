#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
	public:
		SpellBook(void);
		~SpellBook(void);

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const & spell);
		ASpell*	createSpell(std::string const & spell);

	private:
		SpellBook(const SpellBook& src);
		SpellBook& operator=(const SpellBook& src);

		std::vector<ASpell*>	list;
};

#endif
