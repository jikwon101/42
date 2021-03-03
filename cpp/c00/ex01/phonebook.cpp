#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->num_of_contacts = 0;
}

bool Phonebook::AddContact(void)
{
	if (this->num_of_contacts == 8)
	{
		std::cout << "Phonebook is already full.\n";
		return (false);
	}
	this->list[this->num_of_contacts].SetInfo(this->num_of_contacts);
	this->num_of_contacts++;
	return (true);
}

int Phonebook::ConvertToInt(char c)
{
	return (c - '0');
}

bool Phonebook::SearchPhonebook(void)
{
	char	tmp;
	int		input;

	if (this->num_of_contacts == 0)
	{
		std::cout << "Add a contact first." << std::endl;
		return (true);
	}
	ShowSearchPrompt();
	while (1)
	{	
		std::cout << "Enter the index you want to see or 9 to exit." << std::endl;
		std::cout << ">  ";
		tmp = std::cin.get();
		input = ConvertToInt(tmp);
		std::cin.ignore(100, '\n');

		if (0 <= input && input < this->num_of_contacts)
		{
			this->list[input].GetInfo();
			break ;
		}
		else if (input == 9)
			break;
		else
			std::cout << "Wrong number" << std::endl;
	}
	std::cout << std::endl;
	return (true);
}

bool Phonebook::ShowSearchPrompt(void)
{	
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < this->num_of_contacts; i++)
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		this->list[i].GetPromptList();
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	return (true);
}


