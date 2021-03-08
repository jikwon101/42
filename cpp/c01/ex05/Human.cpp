#include "Human.hpp"

const Brain& Human::getBrain() const
{
	return (this->my_brain);
}

std::string Human::identify(void)
{
	std::string temp;

	temp = this->my_brain.identify();
	return (temp);
}
