#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName(void) const
{
	return name;
}

const std::string&	Warlock::getTitle(void) const
{
	return title;
}

void	Warlock::setTitle(const std::string& _title)
{
	title = _title;
}

void	Warlock::introduce(void) const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	book.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string nameSpell)
{
	book.forgetSpell(nameSpell);
}

void	Warlock::launchSpell(std::string nameSpell, const ATarget& target)
{
	ASpell		*spell;

	if ((spell = book.createSpell(nameSpell)) != 0)
	{
		spell->launch(target);
		delete spell;
	}
}
