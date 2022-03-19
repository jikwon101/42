#include "phonebook.hpp"

std::string Contact::s_header[11] = {
	"Frist name",
	"Last name",
	"Nickname",
	"Login",
	"Postal address",
	"Email address",
	"Phone number",
	"Birthdat data",
	"Favorite meal",
	"Underwear color",
	"Darkest secret"
};

bool Contact::GetPromptList(void)
{
	int i = 0;

	std::cout << "|" << std::right << std::setw(10) << this->index;
	while (i < 3)
	{
		if (this->info[i].length() > 10)
			std::cout << "|" << this->info[i].substr(0, 9) << ".";
		else
			std::cout << "|" << std::right << std::setw(10) << this->info[i];
		i++;
	}
	std::cout << "|" << std::endl;
	return (true);
}

bool Contact::GetInfo(void)
{
	int i = 0;
	int width = 15;

	while (i < 11)
	{
		std::cout << std::left << std::setw(width) << s_header[i] << " : " << info[i] << std::endl;
		i++;
	}
	return (true);
}

bool Contact::SetInfo(int index)
{
	int i = 0;

	this->index = index + 1;
	while (i < 11)
	{
		std::cout << "[" << i + 1 << "/11] ";
		std::cout << "Enter your " << s_header[i] << std::endl;
		std::cout << "+  ";
		getline(std::cin, this->info[i]);
		i++;
	}
	std::cout << "Successfully added" << std::endl <<std::endl;
	return (true);
}
