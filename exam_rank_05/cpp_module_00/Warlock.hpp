#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);
	
		const std::string&	getName() const;
		const std::string&	getTitle() const;

		void	setTitle(const std::string& _title);
		void	introduce(void) const;

	private:
		std::string name;
		std::string title;
		
		Warlock(void);
		Warlock(const Warlock& src);	
		Warlock& operator=(const Warlock& src);
};

#endif
