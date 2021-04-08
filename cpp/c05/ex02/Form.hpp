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
	bool				is_signed;
	std::string			target;

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
	class NotSigned : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class NotHighEnoughGrade : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class CantOpenFile : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

	Form(std::string name, std::string target, int sign_grade, int execute_grade) throw(GradeTooHighException, GradeTooLowException);
	virtual ~Form();
	Form(Form const & src);
	Form& operator=(Form const & src);
	void				setTarget(std::string target);
	std::string			getName(void) const;
	std::string			getTarget(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(Bureaucrat const & src) throw (GradeTooLowException);
	virtual void		execute(Bureaucrat const & executor) const throw (NotSigned, NotHighEnoughGrade, CantOpenFile) = 0;
};

std::ostream& operator<<(std::ostream& os, Form const & src);

#endif
