#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
private:
	const Brain my_brain;

public:
	Human();
	std::string identify(void);
	const Brain& getBrain() const;
};

#endif
