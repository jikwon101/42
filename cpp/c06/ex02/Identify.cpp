#include "Identify.hpp"

void	identify_from_pointer(Base *p)
{
	void *ptr;

	if ((ptr = dynamic_cast<A *>(p)) != 0)
		std::cout << "A\n";
	else if ((ptr = dynamic_cast<B *>(p)) != 0)
		std::cout << "B\n";
	else if ((ptr = dynamic_cast<C *>(p)) != 0)
		std::cout << "C\n";
}

void 	identify_from_reference(Base & p)
{
	void *ptr;

	if ((ptr = dynamic_cast<A *>(&p)) != 0)
		std::cout << "A\n";
	else if ((ptr = dynamic_cast<B *>(&p)) != 0)
		std::cout << "B\n";
	else if ((ptr = dynamic_cast<C *>(&p)) != 0)
		std::cout << "C\n";
}
