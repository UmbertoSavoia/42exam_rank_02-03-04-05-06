#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget(void);
		ATarget(std::string type);
		ATarget(const ATarget& src);
		virtual ~ATarget(void);
		ATarget& operator=(const ATarget& src);
	
		const std::string&	getType(void) const;
		virtual ATarget*	clone(void) const = 0;
		void				getHitsBySpell(const ASpell& spell) const;

	private:
		std::string	type;
};

#endif
