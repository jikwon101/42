#include "Conversion.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Conversion field(av[1]);
		std::cout << field;
	}
	return (0);
}
