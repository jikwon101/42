#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
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
	
	Bureaucrat();
	std::string			name;
	int					grade;
	void				setName(std::string const);
	void				setGrade(int const) throw (GradeTooHighException, GradeTooLowException);

public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat & src);
	Bureaucrat& operator=(Bureaucrat & src);
	std::string			getName(void) const;
	int					getGrade(void) const;
	void				upGrade(void); 
	void				downGrade(void);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & src);

#endif
