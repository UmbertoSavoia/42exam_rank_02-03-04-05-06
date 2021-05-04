#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void)
{
	std::vector<ASpell*>::iterator it = list.begin();
	std::vector<ASpell*>::iterator ite = list.end();

	while (it != ite)
	{
		delete *it;
		it++;
	}
}

void	SpellBook::learnSpell(ASpell* spell)
{
	std::vector<ASpell*>::iterator it = list.begin();
	std::vector<ASpell*>::iterator ite = list.end();

	for ( ; it != ite; it++)
		if ((*it)->getName() == spell->getName())
			return ;
	list.push_back(spell->clone());
}

void	SpellBook::forgetSpell(std::string const & spell)
{
	std::vector<ASpell*>::iterator it = list.begin();
	std::vector<ASpell*>::iterator ite = list.end();

	while (it != ite)
	{
		if ((*it)->getName() == spell)
		{
			delete *it;
			it = list.erase(it);
		}
		else
			it++;
	}
}

ASpell*	SpellBook::createSpell(std::string const & spell)
{
	std::vector<ASpell*>::iterator it = list.begin();
	std::vector<ASpell*>::iterator ite = list.end();

	for ( ; it != ite; it++)
		if ((*it)->getName() == spell)
			return ((*it)->clone());
	return 0;
}
