#include "Human.hpp"

Human::Human():my_brain()
{}
const Brain& Human::getBrain() const
{
	return (this->my_brain);
}

std::string Human::identify(void)
{
	return (this->my_brain.identify());
}
