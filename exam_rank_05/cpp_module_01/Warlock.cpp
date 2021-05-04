#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << name << ": My job here is done!" << std::endl;
	for (std::vector<ASpell*>::iterator it = list.begin(); it != list.end();)
	{
		delete (*it);
		it = list.erase(it);
	}
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

void	Warlock::learnSpell(const ASpell* spell)
{
	std::vector<ASpell*>::iterator itend = list.end();
	for (std::vector<ASpell*>::iterator begin = list.begin(); begin != itend; begin++)
		if ((*begin)->getName() == (*spell).getName())
			return ;
	list.push_back(spell->clone());
}

void	Warlock::forgetSpell(std::string nameSpell)
{
	std::vector<ASpell*>::iterator itend = list.end();
	for (std::vector<ASpell*>::iterator begin = list.begin(); begin != itend; begin++)
	{
		if ((*begin)->getName() == nameSpell)
		{
			delete *begin;
			begin = list.erase(begin);
		}
	}
}

void	Warlock::launchSpell(std::string nameSpell, const ATarget& target)
{
	std::vector<ASpell*>::iterator itend = list.end();
	for (std::vector<ASpell*>::iterator begin = list.begin(); begin != itend; begin++)
	{
		if ((*begin)->getName() == nameSpell)
		{
			(*begin)->launch(target);
			return ;
		}
	}
}
