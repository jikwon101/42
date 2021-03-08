#include "sed.hpp"

int main(int ac, char **av)
{
	int ret;
	Sed sedfield;

	if (ac != 4)
	{
		std::cout << "Error: Invalid arguments" << std::endl;
		return (false);
	}
	ret = sedfield.sed(av[1], av[2], av[3]);
	return (ret);
}
