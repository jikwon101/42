#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

class Intern 
{
private:
	Form		*makeShruberryCreation(std::string target);
	Form		*makeRobotomyRequest(std::string target);
	Form		*makePresidentialPardon(std::string target);
	std::string	removeSpace(std::string str);
	bool 		compareIgnoreCase(std::string s1, std::string s2);
public:
	class NotFound: public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	Intern();
	~Intern();
	Intern(Intern const & src);
	Intern& operator=(Intern const & src);
	Form* makeForm(std::string kind, std::string target) throw(NotFound);
};
#endif
