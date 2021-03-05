#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class	Contact {

private:
	int					index;
	std::string			info[11];
	static std::string	s_header[11];

public:
	bool				GetPromptList(void);
	bool				GetInfo(void);
	bool 				SetInfo(int index);
};
#endif
