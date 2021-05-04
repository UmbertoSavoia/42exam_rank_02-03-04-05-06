#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator
{
	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(std::string const & target);
		ATarget*	createTarget(std::string const & target);

	private:
		TargetGenerator(const TargetGenerator& src);
		TargetGenerator& operator=(const TargetGenerator& src);
		std::vector<ATarget*>	list;
};

#endif
