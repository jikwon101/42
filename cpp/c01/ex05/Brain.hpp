#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
public:
public:
	std::string identify(void) const;
	uintptr_t getAddress(const Brain &my) const;
};
#endif
