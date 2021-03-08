#include "Brain.hpp"

Brain::Brain()
{
	neuron = 0;
}

std::string Brain::identify(void) const
{
	std::stringstream buff;
	
	buff << this;
	return (buff.str());
}
