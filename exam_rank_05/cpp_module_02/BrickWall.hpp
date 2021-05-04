#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall(void);
		BrickWall(std::string type);
		BrickWall(const BrickWall& src);
		BrickWall& operator=(const BrickWall& src);
		virtual ~BrickWall(void);

		virtual ATarget*	clone(void) const;
};

#endif
