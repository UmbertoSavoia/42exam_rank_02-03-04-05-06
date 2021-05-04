#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void)
{
	std::vector<ATarget*>::iterator it = list.begin();
	std::vector<ATarget*>::iterator ite = list.end();

	while (it != ite)
	{
		delete *it;
		it++;
	}
}

void		TargetGenerator::learnTargetType(ATarget* target)
{
	std::vector<ATarget*>::iterator it = list.begin();
	std::vector<ATarget*>::iterator ite = list.end();

	for ( ; it != ite; it++)
		if ((*it)->getType() == target->getType())
			return ;
	list.push_back(target->clone());
}

void		TargetGenerator::forgetTargetType(std::string const & target)
{
	std::vector<ATarget*>::iterator it = list.begin();
	std::vector<ATarget*>::iterator ite = list.end();

	while (it != ite)
	{
		if ((*it)->getType() == target)
		{
			delete *it;
			it = list.erase(it);
		}
		else
			it++;
	}
}

ATarget*	TargetGenerator::createTarget(std::string const & target)
{
	std::vector<ATarget*>::iterator it = list.begin();
	std::vector<ATarget*>::iterator ite = list.end();

	for ( ; it != ite; it++)
		if ((*it)->getType() == target)
			return ((*it)->clone());
	return 0;
}
