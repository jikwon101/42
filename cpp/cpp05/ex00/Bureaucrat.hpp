#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
		
	Bureaucrat();
	std::string	const	name;
	int					grade;
	void				setGrade(int const) throw (GradeTooHighException, GradeTooLowException);


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

	Bureaucrat(std::string name, int grade) throw (GradeTooHighException, GradeTooLowException);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat& operator=(Bureaucrat const & src);
	std::string			getName(void) const;
	int					getGrade(void) const;
	void				upGrade(void); 
	void				downGrade(void);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & src);

#endif
