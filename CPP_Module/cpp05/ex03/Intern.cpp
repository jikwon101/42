#include "Intern.hpp"

/*
** Exception
*/
const char *Intern::NotFound::what(void) const throw()
{
	return ("NotFound");
}

/*
** Coplien's Form
*/
Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern& Intern::operator=(Intern const & src)
{
	(void)src;
	return (*this);
}


/*
** Member Function
*/

typedef Form* (Intern::*MAKE)(std::string target);

Form*		Intern::makeForm(std::string kind, std::string target) throw (NotFound)
{
	int res = -1;
	static const std::string form[] = {"ShrubberyCreationForm", "ShrubberyCreation", "RobotomyRequestForm", "RobotomyRequest", "PresidentialPardonForm", "PresidentialPardon"};
	MAKE make[] = {&Intern::makeShruberryCreation, &Intern::makeRobotomyRequest, &Intern::makePresidentialPardon};
	
	for (int i = 0; i < 6 ; i++)
	{
		if (compareIgnoreCase(form[i], removeSpace(kind)) == true)
		{
			res = i;
			break;
		}
	}
	if (res < 0)
	{
		std::cout << "Can't make form." << std::endl;
		throw (NotFound());
	}
	std::cout << "Intern creates " << form[res - res % 2] << std::endl;
	return ((this->*make[res / 2])(target));
}

std::string Intern::removeSpace(std::string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return (str);
}

bool		Intern::compareIgnoreCase(std::string s1, std::string s2)
{
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	if (s1 == s2)
		return (true);
	return (false);
}

Form*		Intern::makeShruberryCreation(std::string target)
{
	Form *result = new ShrubberyCreationForm(target);
	return (result);
}

Form*		Intern::makeRobotomyRequest(std::string target)
{
	Form *result = new RobotomyRequestForm(target);
	return (result);
}

Form*		Intern::makePresidentialPardon(std::string target)
{
	Form *result = new PresidentialPardonForm(target);
	return (result);
}


