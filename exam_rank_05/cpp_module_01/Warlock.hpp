#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "ASpell.hpp"
#include "ATarget.hpp"

class	ASpell;
class	ATarget;

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		virtual ~Warlock(void);
	
		const std::string&	getName() const;
		const std::string&	getTitle() const;

		void	setTitle(const std::string& _title);
		void	introduce(void) const;

		void	learnSpell(const ASpell* spell);
		void	forgetSpell(std::string nameSpell);
		void	launchSpell(std::string nameSpell, const ATarget& target);

	private:
		std::string 			name;
		std::string 			title;
		std::vector<ASpell*>	list;
		
		Warlock(void);
		Warlock(const Warlock& src);	
		Warlock& operator=(const Warlock& src);
};

#endif
