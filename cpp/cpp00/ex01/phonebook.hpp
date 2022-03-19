#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class	Phonebook 
{
private:
	Contact	list[8];
	int		num_of_contacts;
	bool	ShowSearchPrompt(void);
	int		ConvertToInt(char c);

public:
	bool	AddContact(void);
	bool	SearchPhonebook(void);
	Phonebook();
};
#endif
