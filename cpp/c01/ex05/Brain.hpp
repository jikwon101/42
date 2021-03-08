#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
public:
	int neuron;
public:
	Brain();
	std::string identify(void) const;
};

#endif
