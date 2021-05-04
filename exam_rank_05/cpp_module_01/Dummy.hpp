#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy(void);
		Dummy(std::string type);
		Dummy(const Dummy& src);
		Dummy& operator=(const Dummy& src);
		virtual ~Dummy(void);

		virtual ATarget*	clone(void) const;
};

#endif