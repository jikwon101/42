#include "Conversion.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Conversion my(av[1]);
		std::cout << my;
	}
	else
		std::cout << "Invalid arguments" << std::endl;
	return (0);
}
