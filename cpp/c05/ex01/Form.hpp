#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
class Form;
#include "Bureaucrat.hpp"

class Form
{
private:
	Form();
	std::string	const	name;
	int	const			sign_grade;
	int const			execute_grade;
	int					is_signed;

public:	
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

	Form(std::string name, int sign_grade, int execute_grade) throw(GradeTooHighException, GradeTooLowException);
	~Form();
	Form(Form const & src);
	Form& operator=(Form const & src);
	std::string			getName(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(Bureaucrat const & src) throw (GradeTooLowException);
};

std::ostream& operator<<(std::ostream& os, Form const & src);

#endif
