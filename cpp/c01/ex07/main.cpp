#include "sed.hpp"

int	error_exit(const char *str)
{
	std::cout << str << std::endl;
	return (false);
}

int main(int ac, char **av)
{
	Sed sedfield;

	if (ac != 4)
		return (error_exit("Error: Invalid arguments"));
	sedfield.setInfo(av[1], av[2], av[3]);
	if (sedfield.readFile() == false)
		return (error_exit("Error: Can't open file"));
	sedfield.sed();
	sedfield.writeFile();
	return (true);
}
