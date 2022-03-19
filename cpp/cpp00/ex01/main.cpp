#include "phonebook.hpp"

int main()
{
	std::string	input;
	Phonebook	my;
	
	std::cout << "My PhoneBook" << std::endl;
	std::cout << "Enter your command : ADD / SEARCH / EXIT" << std::endl;
	while (1)
	{
		input.clear();
		std::cout << ">  ";
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
			my.AddContact();
		else if (input.compare("SEARCH") == 0)
			my.SearchPhonebook();
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Bye" << std::endl;
			break ;
		}
		else
			std::cout << "Not a valid command. Check your command again."  << std::endl;
	}
}
